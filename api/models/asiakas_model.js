const db = require('../database');

const asiakas = {
getById:  function(id, callback) {
          return db.query('select * from asiakas where idasiakas=?', [id], callback);
          },
getAll:   function(callback) {
          return db.query('select * from asiakas', callback);
          },
add:      function(asiakas, callback) {
          return db.query('insert into asiakas (nimi,osoite,puhelinnumero) values(?,?,?)',
          [asiakas.nimi, asiakas.osoite, asiakas.puhelinnro],callback);
          },
delete:   function(id, callback) {
          return db.query('delete from asiakas where idasiakas=?', [id], callback);
          },
update:   function(id, asiakas, callback) {
          return db.query('update asiakas set nimi=?,osoite=?, puhelinnumero=? where idasiakas=?',
          [asiakas.nimi, asiakas.osoite, asiakas.puhelinnro, id], callback);
          }
};
module.exports = asiakas;