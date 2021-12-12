const mysql = require('mysql');
const connection = mysql.createConnection(process.env.mysql);
module.exports = connection;