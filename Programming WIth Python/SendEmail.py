from email.mime.multipart import MIMEMultipart
from email.mime.text import MIMEText
import smtplib
msg = MIMEMultipart();
text = "Write Your Content To Email";
msg['From'] = "Write your Author";
msg['To'] = "Write your Destinatary";
msg['Subject'] = "Write The Subject Title";
msg.attach(MIMEText(text, 'plain'));
server = smtplib.SMTP("smtp.gmail.com", 587);
server.starttls();
password = "Write your password in there";
server.login(msg['From'], password);
server.sendmail(msg['From'], msg['To'], msg.as_string());
server.quit();
print('The message are success send ! ');
# For more security, follow that pass: 1. Entry your Google Account; 2. Search App Password; 3. Write in New App "Send E-mail With Python"; 4. The Google generate one random password and with passoword you use the project, ok ? Good test :)  
