function GetHistory() {
    fetch("https://api.particle.io/v1/devices/4c0032000751353530373132/history?access_token=7dbbca9e394ce880d1c2dc5dd97913dd677c5c1e") // Call the fetch function passing the url of the API as a parameter
      .then(function(response) {
        response.json().then(function(data) {
            console.log(data);
        //   document.getElementById("temp").innerHTML = data["result"].toFixed(1) + "  " + String.fromCharCode(176) + "F";
        //   document.getElementById("timestamp").innerHTML = "Last updated: " + new Date().toLocaleString();
        });
      })
      .catch(function() {});
  
    //   setTimeout(arguments.callee, 1000);
  }
  
  GetHistory();
  