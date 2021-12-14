const db = require('../database');

const del = 
{
    del: function(asiakas_pankkitili, callback)
    {
        return db.query('DELETE FROM asiakas_pankkitili WHERE idasiakas = ? AND tilinumero = ?', [asiakas_pankkitili.idasiakas, asiakas_pankkitili.tilinumero], callback);
    }
}

module.exports = del;