const db = require('../database');

const credit = {
  getAll: function(callback) {
    return db.query('select * from credit', callback);
  },
  getById: function(id, callback) {
    return db.query('select c.luottosaldo, c.idCredit from credit c join kortti k on k.idCredit = c.idCredit where k.kortin_numero=?', [id], callback);
  },
  add: function(credit, callback) {
    return db.query(
      'insert into credit (Tilinumero,Luottosaldo,Luottoraja) values(?,?,?)',
      [credit.Tilinumero, credit.Luottosaldo, credit.Luottoraja],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from credit where idCredit=?', [id], callback);
  },
  update: function(id, credit, callback) {
    return db.query(
      'update credit inner join kortti on kortti.idCredit = credit.idCredit set credit.Luottosaldo=? where kortti.kortin_numero=?',
      [credit.Luottosaldo, id],
      callback
    );
  }
};
module.exports = credit; 