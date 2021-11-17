const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;
const user = 
{
    get: function(callback)
    {
        return db.query('SELECT * FROM kortti');
    },
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM kortti WHERE idKortti = ?', [id], callback);
    },
    add: function(user, callback)
    {
        bcrypt.hash(user.password, saltRounds, function(err, hash)
        {
            return db.query('INSERT INTO kortti (idKortti, pin) values(?, ?', [user.username, hash], callback);
        });
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM kortti WHERE idKortti = ?', [id], callback);
    },
    update: function(id, user, callback)
    {
        bcrypt.hash(user.password, saltRounds, function(err, hash)
        {
            return db.query('UPDATE kortti SET pin = ? WHERE idKortti = ?',
            [user.password, hash, id], callback);
        });
    }
}

module.exports = user;