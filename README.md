# smart-agriculture-iot
Solo hackathon project using ESP8266 and sensors for smart agriculture monitoring.
Team name: FirstBuild
Theme-7: AgriTech & Environment
PS: Precision farming: simulate a farm with multiple zones, integrate live weather data, model crop growth stages, and recommend zone-specific irrigation, fertilization, or pest control actions.
Smart Agriculture IoT System
Sensor	What it gives	Agri meaning
DHT11	Temperature + Humidity	Heat stress
LDR	Light intensity	Crop sunlight exposure
Rain sensor	Rain detection	Skip irrigation / rain alert

Role of 5G:
Role of 5G in this system
•	Low latency alerts
o	Frost & rain alerts must be instant
•	High reliability
o	Works in rural areas where Wi-Fi / Fiber fails
•	Scalability
o	Hundreds of ESP8266 nodes across farm zones
•	Real-time cloud analytics
o	Continuous sensor streaming over 5G



“ESP8266 is used as a low-power field node. 5G is used at the gateway level to reduce cost and power consumption while still enabling wide-area connectivity.”
“In our system, ESP8266-based sensor nodes collect environmental data. These nodes communicate with a nearby edge gateway. The gateway uses a 5G connection to transmit aggregated data to the cloud. 5G provides ultra-low latency and high reliability, which is critical for time-sensitive agricultural alerts like frost and rainfall-based irrigation decisions.”

ESP8266 → Edge Gateway → 5G Network → Cloud → App

“Due to hardware constraints, we simulated the 5G backhaul using WiFi. However, the system architecture is fully compatible with 5G gateways used in real smart farming deployments.”

With gateway (real farms):
ESP8266 → Nearby device → Internet → App
That “nearby device” is the edge gateway.
Why it exists:
•	Sensors are weak
•	Internet is unstable in farms
•	Gateway:
o	collects data from many ESPs
o	sends it using strong network (5G)

“Our ESP8266-based node collects environmental data from the farm. This data is sent to an application through the internet. In real deployment, multiple such nodes connect to an edge gateway, which uses a 5G network to transmit data to the cloud for real-time monitoring and alerts.”
ESP8266 sends sensor data over the internet to Blynk’s server, and your phone app reads it from there.
That server = cloud.
ESP8266 → Internet → Blynk Server → Your Phone
“For the prototype, we implemented one physical sensor node to validate the system. The platform is designed to be scalable, and the same node logic can be replicated across multiple farm zones. In a real deployment, 10 or more identical nodes would send data simultaneously to the cloud.”
“Due to time and hardware constraints, we demonstrated one node. However, our data model, cloud dashboard, and analytics are node-agnostic and support multiple zones without modification.”
Making of the Machine Learning model which predicts if the irrigation is required
• Step 1 – Create the data
•	Look at the columns, types, missing values.
•	Decide which column is the target (Irrigate) and which are inputs (features).
• Step 2 – Prepare data for training
•	Separate features (X) and target (y)
•	Handle missing values, encode categorical variables if needed
•	Split into training set and test set
• Step 3 – Train the ML model
•	Feed the training data to a model (like Decision Tree)
•	Model learns patterns (“If soil moisture low and temp high → irrigate”)
• Step 4 – Test & Evaluate
•	Check how well the model predicts using the test set
•	Metrics: accuracy, confusion matrix
• Step 5 – Predict new data
•	Take new input (the judge’s dataset)
•	Model predicts whether to irrigate
We have 9 parameters/features in total:
1.	Soil_Moisture – numeric (10–70%)
2.	Temperature – numeric (°C)
3.	Humidity – numeric (%)
4.	Rainfall_Last24h – numeric (mm)
5.	Soil_Type – categorical (Sandy, Loam, Clay)
6.	Crop_Type – categorical (Wheat, Rice, Corn, Tomato)
7.	Irrigate – target variable (0/1)
8.	Soil_Deficit – numeric (100 – Soil_Moisture)
9.	Heat_Index – numeric (Temperature × (1 – Humidity/100))

“We model crop growth stages as a categorical variable:
Seedling, Vegetative, Flowering, Maturity.
The required irrigation and fertilization differ at each stage.
In future, this stage becomes an input feature to the ML model.”
