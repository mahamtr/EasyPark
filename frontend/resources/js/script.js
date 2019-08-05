var t = setTimeout(function() {

function loadFile(filePath) {
  var result = null;
  var xmlhttp = new XMLHttpRequest();
  xmlhttp.open("GET", filePath, false);
  xmlhttp.send();
  if (xmlhttp.status==200) {
    result = xmlhttp.responseText;
  }
  return result;
}

  var random = Math.random();

var myStuff = loadFile("http://138.0.229.2/resources/input.txt");
document.getElementById("Disponibles").innerHTML = myStuff;
document.getElementById("Ocupados").innerHTML = myStuff;

}, 500);
