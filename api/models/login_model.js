const db = require('../database');

const login= {
  getById: function(id, callback){
    return db.query('select count(*) AS pass from pankkikortti where korttinumero=?',[id], callback);
  },
  checkPassword: function(korttinumero, callback) {
      return db.query('SELECT pin FROM pankkikortti WHERE korttinumero = ?',[korttinumero], callback); 
      
  }
};
          
module.exports = login;