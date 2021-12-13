const db = require('../database_users');

const login_users =
{
    checkPassword: function(username, callback)
    {
        return db.query('SELECT pWord FROM users WHERE uName = ?', [username], callback);
    }
};

module.exports = login_users;