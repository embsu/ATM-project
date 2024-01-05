const db = require ('../database');
const login ={
    checkPassword:function (login_kortinnumero, callback){
        return db.query('select PIN from kortti where kortin_numero=?',login_kortinnumero, callback);
    }
}

module.exports=login;