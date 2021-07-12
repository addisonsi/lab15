SYSTEM_THREAD(ENABLED);
SYSTEM_MODE(MANUAL);

void myThread1(void *args) {
  while (1) { 
  Serial.println("1");
  delay(1000);
    
  }
}

os_thread_t thread1;
void myThread2(void *args) {
  while (1) {
  Serial.println("2");
  delay(500);
  }
}

os_thread_t thread2;
void myThread3(void *args) {
  while (1) {
    digitalWrite(D7, HIGH);
    delay(250);
    digitalWrite(D7, LOW);
    delay(250);
  }
}

os_thread_t thread3;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  pinMode(D7, OUTPUT);
  Serial.begin(9600);
  os_thread_create(&thread1, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread1, NULL, 1024);
  os_thread_create(&thread2, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread2, NULL, 1024);
  os_thread_create(&thread3, "anyName", OS_THREAD_PRIORITY_DEFAULT, myThread3, NULL, 1024);
  
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  // The core of your code will likely live here.

}