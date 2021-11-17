const mysql = require('mysql');

const connection = mysql.createPool(
    {
        host: 'localhost',
        user: 'testi',
        password: 'testi',
        database: 'pankki'
    }
);


module.exports = connection;