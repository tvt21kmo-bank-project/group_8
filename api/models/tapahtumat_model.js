const db = require('../database');

const tapahtumat = {
getById:  function(id, callback) {
          return db.query('select * from tapahtumat where idtapahtumat=?', [id], callback);
          },
getAll:   function(callback) {
          return db.query('select * from tapahtumat', callback);
          },
add:      function(tapahtumat, callback) {
          return db.query('insert into tapahtumat (korttinumero,tilinumero,aikaleima,tapahtuma,summa,credit) values(?,?,?,?,?,?)',
          [tapahtumat.korttinumero, tapahtumat.tilinumero, tapahtumat.aikaleima,tapahtumat.tapahtuma, tapahtumat.summa, tapahtumat.credit],callback);
          },
delete:   function(id, callback) {
          return db.query('delete from tapahtumat where idtapahtumat=?', [id], callback);
          },
update:   function(id, tapahtumat, callback) {
          return db.query('update tapahtumat set korttinumero=?,tilinumero=?, aikaleima=?,tapahtuma=?,summa=?,credit=? where idtapahtumat=?',
          [tapahtumat.korttinumero, tapahtumat.tilinumero, tapahtumat.aikaleima,tapahtumat.tapahtuma, tapahtumat.summa, tapahtumat.credit, id], callback);
          }
};
module.exports = tapahtumat;