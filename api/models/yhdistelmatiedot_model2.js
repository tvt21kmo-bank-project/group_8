const db = require('../database');

const yhdistelmatiedot = {
    getById: function(id, callback)
    {
        return db.query('SELECT asiakas_pankkitili.idasiakas, asiakas_pankkitili.tilinumero, saldo, nimi, osoite, puhelinnro FROM asiakas_pankkitili LEFT JOIN asiakas ON asiakas.idasiakas = asiakas_pankkitili.idasiakas JOIN pankkitili ON asiakas_pankkitili.tilinumero = pankkitili.tilinumero WHERE asiakas_pankkitili.idasiakas = ?;', [id], callback);
    }
};

module.exports = yhdistelmatiedot;