const db = require('../database');

const asiakas = {
    getAll: function (callback) {
        return db.query('select * from asiakas', callback);
    },
    getById: function (id, callback) {
        return db.query('select * from asiakas where idasiakas=?', [id], callback);
    },
    add: function (asiakas, callback) {
            return db.query('insert into asiakas (Etunimi,Sukunimi,Hetu,sposti) values(?,?,?,?)',
                [asiakas.Etunimi, asiakas.Sukunimi, asiakas.Hetu, asiakas.sposti],
                callback
        );
    },
    delete: function (id, callback) {
        return db.query('delete from asiakas where idasiakas=?', [id], callback);
    },
    update: function (id, asiakas, callback) { 
            return db.query('update asiakas set Etunimi=?,Sukunimi=?,Hetu=?,sposti=? where idAsiakas=?',
                [asiakas.Etunimi, asiakas.Sukunimi, asiakas.Hetu, asiakas.sposti, id],
                callback
        );
    },
};
module.exports = asiakas;