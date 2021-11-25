const mysql = require('mysql');
const connection = mysql.createPool(
    {
        host: 'localhost',
        user: 'user',
        password: '1234',
        database: 'atm'
    }
);
module.exports = connection;