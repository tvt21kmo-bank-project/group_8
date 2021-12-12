const db = require('../database');

const asiakas = {
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM asiakas WHERE idasiakas = ?', [id], callback);
    },
    getAll: function(callback)
    {
        return db.query('SELECT * FROM asiakas', callback);
    },
    add: function(asiakas, callback)
    {
        return db.query(
            'INSERT INTO asiakas(idasiakas, nimi, osoite, puhelinnro) VALUES(NULL, ?, ?, ?)',
            [asiakas.nimi, asiakas.osoite, asiakas.puhelinnro],
            callback
        );
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM asiakas WHERE idasiakas = ?', [id], callback);
    },
    update: function(id, asiakas, callback)
    {
        return db.query(
            'UPDATE asiakas SET nimi = ?, osoite = ?, puhelinnro = ? WHERE idasiakas = ?',
            [asiakas.nimi, asiakas.osoite, asiakas.puhelinnro, id],
            callback
        );
    }
};
module.exports = asiakas;