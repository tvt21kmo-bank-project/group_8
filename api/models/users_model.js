const db = require('../database_users');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const users = {
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM users WHERE idUser = ?', [id], callback);
    },
    getAll: function(callback)
    {
        return db.query('SELECT * FROM users', callback);
    },
    add: function(users, callback)
    {
        bcrypt.hash(users.pWord, saltRounds, function(err, hash)
        {
            return db.query(
                'INSERT INTO users(idUser, uName, pWord) VALUES(NULL, ?, ?)',
                [users.uName, hash],
                callback
            );
        });
        
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM users WHERE idUser = ?', [id], callback);
    },
    update: function(id, users, callback)
    {
        bcrypt.hash(users.pWord, saltRounds, function(err, hash)
        {
            return db.query(
                'UPDATE users SET uName = ?, pWord = ? WHERE idUser = ?',
                [users.uName, users.pWord, id],
                callback
            );
        });
    }
};
module.exports = users;