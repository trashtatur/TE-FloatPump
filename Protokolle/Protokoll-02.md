# Protocol 02
#### April 19th 2018


## API for SMS

The API for SMS provides difficulty, since SMS are costly and as such the API would provide costs that we didn't factor in. As such the following possibilities are considered:
- Instant Messaging API
- Send an Email
- Relay the SMS over your own phone, which requires an App on your own Phone
- Implement the SMS Service as a stub

Most likely we will go with the email option

## Configuration

It is a possibility to provide configuration via a hosted wifi, that the user can connect to via his phone to provide his phone number via a web based form that will then save that information in a config file, that the application can easily read from

## Hardware Sensor

We will most likely go for a humidity sensor and just configure it to a specific setting, fitting our needs.
An actual floating switch is also considered but as it needs a more mechanic approach, it might not be best suited for our design. This is still to be seen.
