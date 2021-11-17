const db = require('../database');

const bank = 
{
    debit: function(postData, callback)
    {
        return db.query('call tilisiirto(?, ?, ?)',
        [postData.id1, postData.id2, postData.summa],
        callback);
     }
    // ,
    // credit: function(postData, callback)
    // {
    //     return db.query('call tilisiirto(?, ?, ?)',
    //     [postData.id1, postData.id2, postData.summa],
    //     callback);
    // }
};

module.exports = bank;