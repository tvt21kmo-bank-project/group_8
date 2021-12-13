const db = require('../database');

const pankki ={
credit_tilisiirto:  function(postData, callback) {
                    return db.query('call credit_tilisiirto(?,?,?,?,?,@a)',
                    [postData.tilinumero1, postData.tilinumero2, postData.creditKayttaja, postData.creditVastaanottaja, postData.summa], callback);
                    },
credit_to_debit:   function(postData, callback) {
                    return db.query('call credit_to_debit(?,?)',
                    [postData.id1, postData.summa], callback);
                    },          
debit_tilisiirto:   function(postData, callback) {
                    return db.query('call debit_tilisiirto(?,?,?,?,?,@a)',
                    [postData.tilinumero1, postData.tilinumero2, postData.creditKayttaja, postData.creditVastaanottaja, postData.summa], callback);
                    },
debit_to_credit:    function(postData, callback) {
                    return db.query('call debit_to_credit(?,?)',
                    [postData.id1, postData.summa], callback);
                    },
otto:               function(postData, callback) {
                    return db.query('call otto(?,?,?)',
                    [postData.id1, postData.summa, postData.luotto], callback);
                    },
otto_transfer:      function(postData, callback) {
                    return db.query('call otto_transfer(?,?)',
                    [postData.id1, postData.summa], callback);
                    },
saldo_katsaus:      function(postData, callback) {
                    return db.query('call saldo_katsaus(?)',
                    [postData.id1], callback);
                    },        
talletus:           function(postData, callback) {
                    return db.query('call talletus(?,?)',
                    [postData.id1, postData.summa], callback);
                    },
talletus_transfer:  function(postData, callback) {
                    return db.query('call talletus_transfer(?,?)',
                    [postData.id1, postData.summa], callback);
                    },
pin_Katsaus:        function(postData, callback) {
                    return db.query('call pin_Katsaus(?,?, @a)',
                    [postData.id1, postData.pin], callback);
                    },
tilitapahtuma_katsaus:  function(postData, callback) {
                        return db.query('call tilitapahtuma_katsaus(?, ?, ?)',
                        [postData.id1, postData.luotto, postData.alkaenRivilta], callback);
                        }

};

module.exports = pankki;