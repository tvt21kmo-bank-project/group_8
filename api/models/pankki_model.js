const db = require('../database');

const pankki ={
kate:       function(postData, callback) {
            return db.query('call tarkistaTilinKate(?,?,?, @a)',
            [postData.korttinro, postData.summa, postData.luotto], callback);
            },

saldo:      function(postData, callback) {
            return db.query('call haeSaldo(?,?, @a)',
            [postData.korttinro, postData.luotto], callback);
            },          

tapahtumat: function(postData, callback) {
            return db.query('call haeTilinTapahtumia(?,?,?,?, @a)',
            [postData.korttinro, postData.luotto, postData.alkaenRivilta, postData.montakoRivia], callback);
            },

nosto:      function(postData, callback) {
            return db.query('call nostaRahaa(?,?,?)',
            [postData.korttinro, postData.summa, postData.luotto],callback);
            },

talletus:   function(postData, callback) {
            return db.query('call talletaRahaa(?,?)',[postData.korttinro, postData.summa],callback);
            }
};

module.exports = pankki;