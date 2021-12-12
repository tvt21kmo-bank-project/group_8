const db = require('../database');

const tilitapahtuma_katsaus = 
{
    getById: function(id, callback)
    {
        return db.query('CALL tilitapahtuma_katsaus(?)', [id], callback);
    }
};

module.exports = tilitapahtuma_katsaus;