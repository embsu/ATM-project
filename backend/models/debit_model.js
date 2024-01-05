const db = require('../database');

const debit = {
  getAll: function(callback) {
    return db.query('select * from debit', callback);
  },
  getById: function(id, callback) {
    return db.query('select * from debit where idDebit=?', [id], callback);
  },
  getByUsername: function(user, callback) {
    return db.query('select d.saldo, d.idDebit from debit d join kortti k on k.idDebit = d.idDebit where k.kortin_numero=?', [user], callback);
  },
  updateByUsername: function(user, debit, callback) {
    return db.query(
      'update debit inner join kortti on kortti.idDebit = debit.idDebit set debit.Saldo=? where kortti.kortin_numero=?',
      [debit.Saldo, user],
      callback
    );
  },
  add: function(debit, callback) {
    return db.query(
      'insert into debit (Tilinumero,Saldo) values(?,?)',
      [debit.Tilinumero, debit.Saldo],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from debit where idDebit=?', [id], callback);
  },
  update: function(id, debit, callback) {
    return db.query(
      'update debit set Tilinumero=?,Saldo=? where idDebit=?',
      [debit.Tilinumero, debit.Saldo, id],
      callback
    );
  }
};
module.exports = debit;