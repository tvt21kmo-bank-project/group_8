const db = require('../database');
const bcrypt = require('bcryptjs');

const saltRounds = 10;

const pankkikortti = {
    getById: function(id, callback)
    {
        return db.query('SELECT * FROM pankkikortti WHERE korttinumero = ?', [id], callback);
    },
    getAll: function(callback)
    {
        return db.query('SELECT * FROM pankkikortti', callback);
    },
    getAsiakastiedoillaById: function(id, callback)
    {
        return db.query('select * from pankkikortti join asiakas on asiakas.idasiakas = pankkikortti.idasiakas where korttinumero=?',[id], callback);
    },
    add: function(pankkikortti, callback)
    {
        bcrypt.hash(pankkikortti.pin, saltRounds, function(err, hash)
        {
            return db.query(
                'INSERT INTO pankkikortti(korttinumero, credit, tilinumero, pin, idasiakas, pinVaarin) VALUES(NULL, ?, ?, ?, ?, 0)',
                [pankkikortti.credit, pankkikortti.tilinumero, hash, pankkikortti.idasiakas],
                callback
            );
        });
    },
    delete: function(id, callback)
    {
        return db.query('DELETE FROM pankkikortti WHERE korttinumero = ?', [id], callback);
    },
    update: function(id, pankkikortti, callback)
    {
        bcrypt.hash(pankkikortti.pin, saltRounds, function(err, hash)
        {
            return db.query(
                'UPDATE pankkikortti SET pin = ?, credit = ?, tilinumero = ?, pinVaarin = ? WHERE korttinumero = ?',
                [hash, pankkikortti.credit, pankkikortti.tilinumero, pankkikortti.pinVaarin, id],
                callback
            );
        });   
    }
};
module.exports = pankkikortti;