const db = require('../database');

const asiakas_pankkitili = {
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM asiakas_pankkitili WHERE idasiakas = ?', [id], callback);
    },
    getAll: function(callback)
    {
        return db.query('SELECT * FROM asiakas_pankkitili', callback);
    },
    add: function(asiakas_pankkitili, callback)
    {
        return db.query(
            'INSERT INTO asiakas_pankkitili(idasiakas, tilinumero) VALUES(?, ?)',
            [asiakas_pankkitili.idasiakas, asiakas_pankkitili.tilinumero],
            callback
        );
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM asiakas_pankkitili WHERE idasiakas = ?', [id], callback);
    },
    update: function(id, asiakas_pankkitili, callback)
    {
        return db.query(
            'UPDATE asiakas_pankkitili SET tilinumero = ? WHERE idasiakas = ?',
            [asiakas_pankkitili.tilinumero, id],
            callback
        );
    }
};
module.exports = asiakas_pankkitili;