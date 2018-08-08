/******************************************************************************
 * Copyright 2018 Google
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
// This file contains your configuration used to connect to Cloud IoT Core

// Wifi newtork details.
const char *ssid = "yourwifi";
const char *password = "yourpasswd";

// Cloud iot details.
const char *project_id = "yourprojectid";
const char *location = "asia-east1";
const char *registry_id = "air";
const char *device_id = "esp32_05C1A0";

// To get the private key run (where private-key.pem is the ec private key
// used to create the certificate uploaded to google cloud iot):
// openssl ec -in <private-key.pem> -noout -text
// and copy priv: part.
// The key length should be exactly the same as the key length bellow (32 pairs
// of hex digits). If it's bigger and it starts with "00:" delete the "00:". If
// it's smaller add "00:" to the start. If it's too big or too small something
// is probably wrong with your key.
const char *private_key_str =
    "43:f9:1d:a0:b9:61:77:2e:7b:c5:b8:78:6b:70:2f:"
    "34:d3:0f:0b:c2:7d:d3:e6:a8:d4:6e:17:88:63:47:"
    "5a:04";
// To get the certificate for your region run:
// openssl s_client -showcerts -connect mqtt.googleapis.com:8883
// Copy the certificate (all lines between and including ---BEGIN CERTIFICATE---
// and --END CERTIFICATE--) to root.cert and put here on the root_cert variable.

/*const char *root_cert =
    "-----BEGIN CERTIFICATE-----\n"
"MIIEjDCCA3SgAwIBAgIIHArfhWDvmzMwDQYJKoZIhvcNAQELBQAwVDELMAkGA1UE"
"BhMCVVMxHjAcBgNVBAoTFUdvb2dsZSBUcnVzdCBTZXJ2aWNlczElMCMGA1UEAxMc"
"R29vZ2xlIEludGVybmV0IEF1dGhvcml0eSBHMzAeFw0xODA3MjQxNjEwMjlaFw0x"
"ODEwMDIxNjAwMDBaMG0xCzAJBgNVBAYTAlVTMRMwEQYDVQQIDApDYWxpZm9ybmlh"
"MRYwFAYDVQQHDA1Nb3VudGFpbiBWaWV3MRMwEQYDVQQKDApHb29nbGUgTExDMRww"
"GgYDVQQDDBNtcXR0Lmdvb2dsZWFwaXMuY29tMIIBIjANBgkqhkiG9w0BAQEFAAOC"
"AQ8AMIIBCgKCAQEAvAqJ5/5RzFzEvj4iRgH5qM7+l8eQKCJqqrDqSDu1oN5NGVzD"
"R1Nw3WJHGYbytx3usfIyl8m7Nz9JqpP3iAYCM+/wk2krBVSdD7ePbm442LNIRA6f"
"U1eUCLe246t9p7Y/ql8Pyq1HsEM8gphR3TxAtDLAe6JnWVbDSbeHyfow0uJIRqtF"
"ITnZvgPJgdJtHN/Zwd7S+M0IvGCErwZOzp101J4A0mLNeqY9ZCWe8yS0Zms622fR"
"UO+ZruW7uvCcfzQOmAAvoq3O62Sdxhrl8gfw398pJ5YDnyGu3VE1kg7iDWG+i+yU"
"7m9A8bPCUt9xUEAfZogBNs9CMpx9SlCK980GtQIDAQABo4IBRzCCAUMwEwYDVR0l"
"BAwwCgYIKwYBBQUHAwEwHgYDVR0RBBcwFYITbXF0dC5nb29nbGVhcGlzLmNvbTBo"
"BggrBgEFBQcBAQRcMFowLQYIKwYBBQUHMAKGIWh0dHA6Ly9wa2kuZ29vZy9nc3Iy"
"L0dUU0dJQUczLmNydDApBggrBgEFBQcwAYYdaHR0cDovL29jc3AucGtpLmdvb2cv"
"R1RTR0lBRzMwHQYDVR0OBBYEFNKWPcYHqEO14rOG4Eet/+oG1nyPMAwGA1UdEwEB"
"/wQCMAAwHwYDVR0jBBgwFoAUd8K4UJpndnaxLcKG0IOgfqZ+ukswIQYDVR0gBBow"
"GDAMBgorBgEEAdZ5AgUDMAgGBmeBDAECAjAxBgNVHR8EKjAoMCagJKAihiBodHRw"
"Oi8vY3JsLnBraS5nb29nL0dUU0dJQUczLmNybDANBgkqhkiG9w0BAQsFAAOCAQEA"
"RPhaBvFz65e2vzmawNK8aCMsWeqg8lsY5BTOu55tPac6PBmaRiaLIfn/+pdo4zsV"
"jN35D4vsnS3qWbcbegH/89T3hk/EOYSdCXi/KteN9QvYHPmKFV85mKfTUHpleBs/"
"UUwMUMv+w3tDpIkRdKQIsMFmBO3N97RwSYb6LUTlNsfJoGImKdIXoH5wAFOP+PqN"
"ClhD4XW1jMmalkrffjfw4Oi1/tklc+cE0m4Z7hyMbLmV+ybp9TQhT0kJCw/3iN5t"
"Cq1VGf2Tl7V/ghi5nxcIFqRQrRR1Iaj0wpU73HQKUMYZJO3mJ5suxSb6loxVMBGn"
"5zbLpgt7XLh/QZ9TUC35rg==\n"
"-----END CERTIFICATE-----\n";*/
