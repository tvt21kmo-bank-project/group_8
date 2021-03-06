const db = require('../database');

const pankkitili = {
getById:  function(id, callback) {
          return db.query('select * from pankkitili where tilinumero=?', [id], callback);
          },
getAll:   function(callback) {
          return db.query('select * from pankkitili', callback);
          },
add:      function(pankkitili, callback) {
          return db.query('insert into pankkitili (saldo,creditsaldo, luottoraja) values(?, ?, ?)',
          [pankkitili.saldo, pankkitili.creditsaldo, pankkitili.luottoraja],callback);
          },
delete:   function(id, callback) {
          return db.query('delete from pankkitili where tilinumero=?', [id], callback);
          },
update:   function(id, pankkitili, callback) {
          return db.query('update pankkitili set saldo=?,creditsaldo=?, luottoraja = ? where tilinumero=?',
          [pankkitili.saldo, pankkitili.creditsaldo, pankkitili.luottoraja, id], callback);
          }
};
module.exports = pankkitili;