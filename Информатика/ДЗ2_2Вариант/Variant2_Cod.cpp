#include <iostream>
#include <string>
#include <pqxx/pqxx>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    try {
        // 1. ПОДКЛЮЧЕНИЕ
        pqxx::connection conn(
            "host=localhost "
            "port=5432 "
            "dbname=DWH "
            "user=postgres "
            "password=StasPost2007 "
        );

        if (!conn.is_open()) {
            cout << "Ошибка подключения!" << endl;
            return 1;
        }

        cout << "Подключено к: " << conn.dbname() << endl;

        // 2. СОЗДАНИЕ ТАБЛИЦ
        pqxx::work w(conn);

        w.exec("DROP TABLE IF EXISTS sales_fact CASCADE");
        w.exec("DROP TABLE IF EXISTS products_dim CASCADE");
        w.exec("DROP TABLE IF EXISTS customers_dim CASCADE");

        w.exec("CREATE TABLE products_dim ("
            "product_id INT PRIMARY KEY,"
            "product_name TEXT,"
            "category TEXT,"
            "price NUMERIC)");

        w.exec("CREATE TABLE customers_dim ("
            "customer_id INT PRIMARY KEY,"
            "customer_name TEXT,"
            "region TEXT)");

        w.exec("CREATE TABLE sales_fact ("
            "sale_id INT PRIMARY KEY,"
            "sale_date DATE,"
            "product_id INT,"
            "customer_id INT,"
            "quantity INT,"
            "amount NUMERIC)");

        // 3. ЗАГРУЗКА ДАННЫХ (используем английские названия чтобы избежать проблем с кодировкой)
        w.exec("INSERT INTO products_dim VALUES "
            "(1, 'Laptop', 'Electronics', 50000),"
            "(2, 'Phone', 'Electronics', 30000)");

        w.exec("INSERT INTO customers_dim VALUES "
            "(1, 'Ivan', 'Moscow'),"
            "(2, 'Maria', 'SPb')");

        w.exec("INSERT INTO sales_fact VALUES "
            "(1, '2024-01-15', 1, 1, 1, 50000),"
            "(2, '2024-01-16', 2, 2, 2, 60000)");

        w.commit();
        cout << "Таблицы созданы и данные загружены" << endl;

        // 4. ВЫПОЛНЕНИЕ ЗАПРОСОВ
        pqxx::nontransaction n(conn);

        cout << "\n1. Sales by category:" << endl;
        pqxx::result r1 = n.exec(
            "SELECT p.category, SUM(s.amount) as total "
            "FROM sales_fact s "
            "JOIN products_dim p ON s.product_id = p.product_id "
            "GROUP BY p.category"
        );

        for (auto row : r1) {
            cout << "Category: " << row[0].as<string>()
                << ", Total: " << row[1].as<double>() << endl;
        }

        cout << "\n2. Sales by region:" << endl;
        pqxx::result r2 = n.exec(
            "SELECT c.region, COUNT(*) as count "
            "FROM sales_fact s "
            "JOIN customers_dim c ON s.customer_id = c.customer_id "
            "GROUP BY c.region"
        );

        for (auto row : r2) {
            cout << "Region: " << row[0].as<string>()
                << ", Count: " << row[1].as<int>() << endl;
        }

        cout << "\n3. Average check:" << endl;
        pqxx::result r3 = n.exec("SELECT AVG(amount) FROM sales_fact");
        cout << "Average: " << r3[0][0].as<double>() << endl;

        cout << "\nDone!" << endl;

    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}