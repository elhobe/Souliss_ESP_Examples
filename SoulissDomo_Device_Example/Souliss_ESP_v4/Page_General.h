///
//  HTML PAGE
//

const char PAGE_AdminGeneralSettings[] PROGMEM =  R"=====(
<meta name="viewport" content="width=device-width, initial-scale=1" />
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<a href="admin.html"  class="btn btn--s"><</a>&nbsp;&nbsp;<strong>Souliss Slot Settings</strong>
<hr>
<form action="" method="post">
<table border="0"  cellspacing="0" cellpadding="3" >
  <tr>
    <td align="left">Node Name</td>
    <td><input type="text" id="devicename" name="devicename" value="" maxlength="10"></td>
  </tr>
  <tr id="Emoncms">
    <td align="left">Emoncms API</td>
    <td><input type="text" id="API" name="API" value="" maxlength="32"></td>
    <td align="left">Send Sensors?: </td>
    <td><input type="checkbox" id="Send_Emon" name="Send_Emon"></td>
  </tr>
	<tr><td>Sensors Configuration:</td><td>
	<select  id="byte0" name="byte0" onchange="getComboA(this)">
		<option value="0">None</option>
		<option value="1">DHT |........|.......</option>
		<option value="2">.......| LDR |.......</option>
		<option value="3">.......|........| DALLAS</option>
		<option value="4">DHT | LDR |.......</option>
		<option value="5">DHT |........| DALLAS</option>
		<option value="6">.......| LDR | DALLAS</option>
		<option value="7">DHT | LDR | DALLAS</option>
	</select>
	</td></tr>
	
	<tr id="DHT">
        	<td align="left"> DHT Type:</td><td>
		<select  id="dht_type" name="dht_type">
			<option value="0">DHT11</option>
			<option value="1">DHT22</option>
		</select>
	</td></tr>
	
	<tr id="Dallas">
        <td align="left"> Dallas Qty:</td>
        <td><input type="text" id="dallas_qty" name="dallas_qty" size="2" value="1"></td>
	</tr>

	<tr><td>Lights Output Mode:</td><td>
	<select  id="byte1" name="byte1" onchange="getComboB(this)">
		<option value="0">None</option>
		<option value="1">ON-OFF MODE</option>
    <option value="2">PULSE MODE</option>
		<option value="3">PWM MODE</option>
		<option value="4">PIR_MODE</option>
		<option value="5">RGB_MODE</option>
    <option value="6">PIR_ALARM_MODE</option>
    <option value="7">THERMOSTAT_MODE</option>
	</select>
	</td></tr>
	
	<tr><td>Others: </td><td>
	<select  id="byte2" name="byte2" onchange="getComboC(this)">
		<option value="0">None</option>
		<option value="1">CAPACITIVE</option>
		<option value="2">RELAY</option>
		<option value="3">PRESSURE SENSOR</option>
		<option value="4">CAPACITIVE_DEBUG</option>
		<option value="5">BUTTONS</option>
		<option value="6">BUTTONS_PULLUP</option>
		<option value="7">ALARM_ENDSTOP</option>
		<option value="8">BUTTONS_2_STATE</option>
		<option value="9">PULSE_OUTPUT</option>
		<option value="10">GARAGE_DOOR</option>
		<option value="11">WINDOW_CURTAIN</option>
		<option value="12">220V_OPTO_AND_RELAY</option>
	</select>
	</td></tr>
	<tr id="Thresold">
		<td align="left" id="cap_thresold_line"> Capacitive Thresold:</td>
		<td><input type="text" id="cap_thresold" name="cap_thresold" size="2" value="5"></td>
	</tr>
	<tr id="Altitude">
		<td align="left" id="Altitude_line"> Altitude:</td>
		<td><input type="text" id="Altitude_id" name="Altitude_id" size="2" value="20"></td>
	</tr>
	<tr>
		<td align="left"> Enable IR Receive on this Node?:</td>
		<td><input type="checkbox" id="IR_ENABLE" name="IR_ENABLE"></td>
	</tr>
  <tr>
    <td align="left"> Enable this Node as USART Bridge?:</td>
    <td><input type="checkbox" id="usartbridge" name="usartbridge"></td>
  </tr>
	
<tr><td colspan="2" align="center"><input type="submit" style="width:150px" class="btn btn--m btn--blue" value="Save"></td></tr>
</table>
<strong>Remember Get Souliss Nodes again from the app after Save Settings</strong>
</form>

<script>
 
window.onload = function ()
{
	load("style.css","css", function() 
	{
		load("microajax.js","js", function() 
		{       
        setValues("/admin/generalvalues");				
		});
	});
}
function load(e,t,n){
  if("js"==t){
    var a=document.createElement("script");
    a.src=e,a.type="text/javascript",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)
  }else if("css"==t){
    var a=document.createElement("link");
    a.href=e,a.rel="stylesheet",a.type="text/css",a.async=!1,a.onload=function(){n()},document.getElementsByTagName("head")[0].appendChild(a)
  }
}


function getComboA(sel) {
    var value = sel.value;
    if(value == 1 || value == 4 || value == 5 || value == 7) {
    	document.getElementById("DHT").style.display = "block";  //none;  
    } else { 
    	document.getElementById("DHT").style.display = "none";	
    }
   
    if(value == 3 || value == 5 || value == 6 || value == 7) {
     	document.getElementById("Dallas").style.display = "block";  //none;  
  	} else {
  		document.getElementById("Dallas").style.display = "none"; 	
  	}
}

function getComboB(sel) {
    var value = sel.value;
    
}

function getComboC(sel) {
    var value = sel.value;
    if(value == 1 || value == 4) {
    	document.getElementById("Thresold").style.display = "block";  //none;  
    } else { 
    	document.getElementById("Thresold").style.display = "none";	
    }
   
    if(value == 3) {
     	document.getElementById("Altitude").style.display = "block";  //none;  
  	} else {
  		document.getElementById("Altitude").style.display = "none"; 	
  	}
}
 
</script>
)=====";

void send_general_html()
{
	
	if (server.args() > 0 )  // Save Settings
	{
		byte0 = 0;
		byte1 = 0;
		byte2 = 0;
		String temp = "";
		usartbridge = false;
		for ( uint8_t i = 0; i < server.args(); i++ ) {
		    if (server.argName(i) == "byte0") byte0 = server.arg(i).toInt(); 
		    if (server.argName(i) == "byte1") byte1 = server.arg(i).toInt();
		    if (server.argName(i) == "byte2") byte2 = server.arg(i).toInt(); 
     		if (server.argName(i) == "cap_thresold") cap_thresold = server.arg(i).toInt();
      	if (server.argName(i) == "Altitude_id") ALTITUDE = server.arg(i).toInt();
      	if (server.argName(i) == "usartbridge") usartbridge = true;
      	if (server.argName(i) == "devicename") DeviceName = urldecode(server.arg(i)); 
      	if (server.argName(i) == "API") API = urldecode(server.arg(i));
      	if (server.argName(i) == "Send_Emon") Send_Emon = true; 
      	if (server.argName(i) == "dht_type") dht_type = server.arg(i).toInt(); 
      	if (server.argName(i) == "dallas_qty") dallas_qty = server.arg(i).toInt(); 
      	if (server.argName(i) == "IR_ENABLE") IR_ENABLE = true; 
		}
		WriteConfig_Slots();
		//firstStart = true;
		ESP.restart();
	}
	server.send ( 200, "text/html", PAGE_AdminGeneralSettings ); 
	LOG.println(__FUNCTION__); 
	
	
}

void send_general_configuration_values_html()
{
	String values ="";
	values += "byte0|" +  (String) byte0 + "|input\n";
	values += "byte1|" +  (String) byte1 + "|input\n";
	values += "byte2|" +  (String) byte2 + "|input\n";
	values += "cap_thresold|" +  (String) cap_thresold + "|input\n";
	values += "Altitude_id|" +  (String) ALTITUDE + "|input\n";
	values += "usartbridge|" +  (String) (usartbridge ? "checked" : "") + "|chk\n";
	values += "devicename|" +  (String)  DeviceName +  "|input\n";
	values += "API|" +  (String)  API +  "|input\n";
	values += "Send_Emon|" +  (String) (Send_Emon ? "checked" : "") + "|chk\n";
	values += "dht_type|" +  (String)  dht_type +  "|input\n";
	values += "dallas_qty|" +  (String)  dallas_qty +  "|input\n";
	values += "IR_ENABLE|" +  (String) (IR_ENABLE ? "checked" : "") + "|chk\n";
	server.send ( 200, "text/plain", values);
	LOG.println(__FUNCTION__); 
}
