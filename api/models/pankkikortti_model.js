const db = require('../database');
const bcrypt = require('bcryptjs');
const { query } = require('express');

const saltRounds = 10;

const pankkikortti ={
get:        function(callback){
            return db.query('select * from pankkikortti', callback);
            },
getById:    function(id, callback){
            return db.query('select * from pankkikortti join asiakas on asiakas.idasiakas = pankkikortti.idasiakas where korttinumero=?',[id], callback);
            },
add:        function(pankkikortti, callback){
            bcrypt.hash(pankkikortti.pin, saltRounds, function(err, hash){
            return db.query('insert into pankkikortti (pin, credit, tilinumero, idasiakas, pinVaarin) values(?, ?, ?, ?, ?)',
            [hash, pankkikortti.credit, pankkikortti.tilinumero, pankkikortti.idasiakas, 0], callback);
            });
            },
delete:     function(id, callback){
            return db.query('delete from pankkikortti where korttinumero=?', [id], callback);
            },
update:     function(id, pankkikortti, callback){
            bcrypt.hash(pankkikortti.pin, saltRounds, function(err, hash){
            return db.query('update pankkikortti set pin=?, credit=?, tilinumero=?, idasiakas=?, pinVaarin = ? where korttinumero=?',
            [hash, pankkikortti.credit, pankkikortti.tilinumero, pankkikortti.idasiakas, pankkikortti.pinVaarin, id], callback);
            });
            },
pin:        function(postData, callback) {
            return db.query('call pinVaarin(?,?, @lkm)',[postData.korttinumero, postData.pin], callback);
            }
};
module.exports = pankkikortti;