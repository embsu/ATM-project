const db = require('../database');

const tapahtumat = {
  getAll: function(callback) {
    return db.query('SELECT idTapahtumat, DATE_FORMAT(Paivamaara,"%a %d.%m.%Y %k:%i") AS Paivamaara, Tyyppi, Maara, idCredit FROM tapahtumat WHERE idCredit IS NOT NULL AND idDebit IS NULL ORDER BY Paivamaara DESC', callback);
  },
  getById: function(kortinNumero, callback) {
      return db.query ('SELECT t.Maara, t.Tyyppi, DATE_FORMAT(t.Paivamaara, "%a %d.%m.%Y %k:%i") AS Paivamaara, t.idCredit FROM tapahtumat t JOIN kortti k ON t.idCredit = k.idCredit WHERE k.Kortin_numero = ? ORDER BY t.Paivamaara DESC LIMIT 5;', [kortinNumero], callback);
  },
  add: function(tapahtumat, callback) {
    return db.query(
      'insert into tapahtumat (Paivamaara,Tyyppi,Maara,idCredit,idDebit) values(?,?,?,?,?)',
      [tapahtumat.Paivamaara, tapahtumat.Tyyppi, tapahtumat.Maara,tapahtumat.idCredit, tapahtumat.idDebit],
      callback
    );
  },
  delete: function(id, callback) {
    return db.query('delete from tapahtumat where idTapahtumat=?', [id], callback);
  },
  update: function(id, tapahtumat, callback) {
    return db.query(
      'update tapahtumat set Paivamaara=?,Tyyppi=?, Maara=?, idCredit=?, idDebit=? where idTapahtumat=?',
      [tapahtumat.Paivamaara, tapahtumat.Tyyppi, tapahtumat.Maara,tapahtumat.idCredit, tapahtumat.idDebit, id],
      callback
    );
  }
};
module.exports = tapahtumat;