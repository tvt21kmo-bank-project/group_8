const mysql = require('mysql');
const connection = mysql.createPool(
    {
        host: 'localhost',
        user: 'user1',
        password: '1234',
        database: 'saulindb'
    }
);
module.exports = connection;