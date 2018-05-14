- Email sent via SMTP protocoll (https://tools.ietf.org/html/rfc5321)
- Connecting to WiFi via standards specified in 8021.x (https://tools.ietf.org/html/rfc3580)
- Client right now connects to hardcoded WiFi, using direct 8021.x specified SSID and password with no encryption
	- hardcoded since a responsive webserver that accepts text input from HTML forms through client requests was out of our expertise to do on an Arduino Board
- It was supposed to use a webform supplied from a http server on Port 80, where a client would supply text/html content via webform, sent through a request to the 
arduino server, which would read out the data of the sent request to retrieve the formdata and use that for WiFi Authentication. Sadly this did not work, as implementing afully functional webserver on an Arduino board is much more complicated than we anticipated
