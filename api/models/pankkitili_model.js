const db = require('../database');

const pankkitili = {
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM pankkitili WHERE tilinumero = ?', [id], callback);
    },
    getAll: function(callback)
    {
        return db.query('SELECT * FROM pankkitili', callback);
    },
    add: function(pankkitili, callback)
    {
        return db.query(
            'INSERT INTO pankkitili(saldo, creditsaldo, luottoraja) VALUES(?, ?, ?)',
            [pankkitili.saldo, pankkitili.creditsaldo, pankkitili.luottoraja],
            callback
        );
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM pankkitili WHERE tilinumero = ?', [id], callback);
    },
    update: function(id, pankkitili, callback)
    {
        return db.query(
            'UPDATE pankkitili SET saldo = ?, creditsaldo = ? WHERE tilinumero = ?',
            [pankkitili.saldo, pankkitili.creditsaldo, id],
            callback
        );
    }
};
module.exports = pankkitili;