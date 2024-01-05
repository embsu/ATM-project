const db = require('../database');
const bcrypt = require ('bcryptjs');
const saltrounds=10;
const kortti = {
  getAll: function(callback) {
    return db.query('select * from kortti', callback);
  },
  getById: function(user, callback) {
    return db.query('select * from kortti where kortin_numero=?', [user], callback);
  },
  add: function(kortti, callback) {
    bcrypt.hash(kortti.PIN, saltrounds, function (err, hashed_password){
    return db.query('insert into kortti (PIN,kortin_numero,Tyyppi,idAsiakas,idCredit,idDebit) values(?,?,?,?,?,?)',
      [hashed_password, kortti.kortin_numero, kortti.Tyyppi, kortti.idAsiakas, kortti.idCredit, kortti.idDebit],
      callback);
  });
  },
  delete: function(id, callback) {
    return db.query('delete from kortti where idKortti=?', [id], callback);
  },
  update: function(id, kortti, callback) {
    bcrypt.hash(kortti.PIN, saltrounds, function (err, hashed_password){
    return db.query(
      'update kortti set PIN=?,kortin_numero=?,Tyyppi=?,idAsiakas=?,idCredit=?,idDebit=? where idKortti=?',
      [hashed_password, kortti.kortin_numero, kortti.Tyyppi, kortti.idAsiakas, kortti.idCredit, kortti.idDebit, id],
      callback);
  });
  },
};
module.exports = kortti;