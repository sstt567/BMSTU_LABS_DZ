CREATE TABLE products_dim (
    product_id INT PRIMARY KEY,
    product_name TEXT,
    category TEXT,
    price NUMERIC
);

CREATE TABLE customers_dim (
    customer_id INT PRIMARY KEY,
    customer_name TEXT,
    region TEXT
);

CREATE TABLE sales_fact (
    sale_id INT PRIMARY KEY,
    sale_date DATE,
    product_id INT,
    customer_id INT,
    quantity INT,
    amount NUMERIC
);

CREATE INDEX idx1 ON sales_fact(product_id);
CREATE INDEX idx2 ON sales_fact(customer_id);
CREATE INDEX idx3 ON sales_fact(sale_date);