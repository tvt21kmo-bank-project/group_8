const db = require('../database');

const asiakas_pankkitili = {
getById:  function(id, callback) {
          return db.query('select * from asiakas_pankkitili where idasiakas=?', [id], callback);
          },
getAll:   function(callback) {
          return db.query('select * from asiakas_pankkitili', callback);
          },
add:      function(asiakas_pankkitili, callback) {
          return db.query('insert into asiakas_pankkitili (tilinumero,idasiakas) values(?,?)',
          [asiakas_pankkitili.tilinumero, asiakas_pankkitili.idasiakas],callback);
          },
delete:   function(id, tilinumero, callback) {
          return db.query('delete from asiakas_pankkitili where idasiakas=? AND tilinumero=?', [id, tilinumero], callback);
          },
update:   function(id, tilinumero, asiakas_pankkitili, callback) {
          return db.query('update asiakas_pankkitili set tilinumero=?,idasiakas=? where idasiakas=? AND tilinumero=?',
          [asiakas_pankkitili.tilinumero, asiakas_pankkitili.idasiakas, id, tilinumero], callback);
          }
};
module.exports = asiakas_pankkitili;