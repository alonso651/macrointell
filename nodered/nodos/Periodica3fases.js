s = msg.payload.object;
var appID = msg.payload.applicationID;
var devEUI = msg.payload.devEUI;
var modelo = "";
var id = "";
var contActiva = "";
var contReactiva = "";
var tiempo ="";
var i = 0;
for (i = 1; i < 13; i++) {
    modelo += String.fromCharCode(s[i]);
}for (i = 14; i < 22; i++) {
    id += String.fromCharCode(s[i]);
}for (i = 22; i < 32; i++) {
    contActiva += String.fromCharCode(s[i]);
}for (i = 32; i < 42; i++) {
    contReactiva += String.fromCharCode(s[i]);
}for (i = 42; i < 50; i++) {
    tiempo += String.fromCharCode(s[f]);
}
var a="";
var b="";
//Contador energia activa
a = contActiva.slice(0, 7);
b = contActiva.slice(7, 10);
contActiva = a.concat(".",b);
var Activa = parseFloat(contActiva);

//Contador energia reactiva 
a = contReactiva.slice(0, 7);
b = contReactiva.slice(7, 10);
contReactiva = a.concat(".",b);
var Reactiva = parseFloat(contReactiva);


    sql = "INSERT INTO HistoLectura(Numero,Modelo,Marca,Contador1,Contador2,TipoLectura,TiempoServicio,devEUI,appID) VALUES ('"+id+"', '"+modelo+"', '"+marca+"', '"+Activa+"', '"+Reactiva+"', '"+tipoLectura+"', '"+tiempo+"', '"+devEUI+"', '"+appID+"');"

//PAYLOAD
msg.payload = {
    "marca":"Elster",
    "modelo":modelo,
    "ID":id,
    "contActiva":Activa,
    "contReactiva":Reactiva,
    "fases":3,
    "lectura":"Periodica",
    "tiempo":tiempo,
    "appID":appID,
    "devEUI":devEUI,
    "sql":sql
}
return msg;