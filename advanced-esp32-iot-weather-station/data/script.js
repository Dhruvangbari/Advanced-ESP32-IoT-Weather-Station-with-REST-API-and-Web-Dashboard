
async function update(){
let res = await fetch('/api/weather');
let data = await res.json();
document.getElementById("temp").innerText = data.temperature;
document.getElementById("hum").innerText = data.humidity;
}
setInterval(update,2000);
