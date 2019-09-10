/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.eucm.ceutec1;
import com.twilio.Twilio;
import com.twilio.rest.api.v2010.account.Message; 
import com.twilio.twiml.MessagingResponse;
import com.twilio.twiml.messaging.Body;
import com.twilio.type.PhoneNumber; 
import static spark.Spark.*;
 import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
/**
 *
 * @author mahamtr mzmaai70@gmail.com
 */


public class main {
         public static final String ACCOUNT_SID = "ACf604eeaffe6e8893a1d8fda39b8ddc84"; 
        public static final String AUTH_TOKEN = "2a168f6910d29bf3ec625a784fd7d0b1"; 

    public static void sendwhatsapp(){
        Message message = Message.creator( 
                new PhoneNumber("whatsapp:+50433112120"), 
                new PhoneNumber("whatsapp:+14155238886"),  
                "Parqueo Ceutec SAP esta Lleno")      
            .create(); 
    }
    
    public static void printreply(String from, String body, String reply){
          System.out.println("Incoming Message from " + from + " with body :" + body);
         System.out.println("Reply Message to " + from + " with body :" + reply);
    }
    
    public static String readCN(){
                String dir = "/Users/mahamtr/Documents/htdocs/resources/var/WCNtotal.txt";
                String x="";
        try (
            FileReader reader = new FileReader(dir);
            BufferedReader br = new BufferedReader(reader)
                  ) 
          {
            String i = br.readLine();
            br.close();
            x = i;
          } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
             return x;
    }
 
    
     public static String readSN(){
                String dir = "/Users/mahamtr/Documents/htdocs/resources/var/WSNtotal.txt";
                String x="";
        try (
            FileReader reader = new FileReader(dir);
            BufferedReader br = new BufferedReader(reader)
                  ) 
          {
            String i = br.readLine();
            br.close();
            x = i;
          } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
             return x;
    }
    
   public static void savecontact(String contact) throws IOException{
       	BufferedWriter writer = new BufferedWriter(new FileWriter("/Users/mahamtr/Documents/htdocs/resources/var/contacts.txt",true));
        writer.write(contact);
        writer.newLine();
        writer.close();
   }
     
   public static boolean findduplicate(String from){
        boolean exist = false;
        String dir = "/Users/mahamtr/Documents/htdocs/resources/var/contacts.txt";
          
        try (
            FileReader reader1 = new FileReader(dir);
            BufferedReader cont = new BufferedReader(reader1)
                  ) 
          {
            while(true){
               String  line = cont.readLine();
               if(line == null) {
                   break;
               }
               if(line.equals(from)){
                   exist = true;
               }
           }

            
            cont.close();
        } catch (IOException e) {
            System.err.format("IOException: %s%n", e);
        }
          return exist;
   }
   
    public static void main(String[] args) {
        String dir = "/Users/mahamtr/NetBeansProjects/PROYECTO_JAVA_2/Read/readInt.txt";
              Twilio.init(ACCOUNT_SID, AUTH_TOKEN); 
            sendwhatsapp();
            post("/sms", (req, res) -> {
                res.type("application/xml");
                String contact = req.queryParams("From");
                if (!findduplicate(contact)) {
                    savecontact(contact);
                    System.out.println("Guardando nuevo contacto : " + contact);
                }
                if(req.queryParams("Body").equalsIgnoreCase("CN")){
               Body body = new Body.Builder(readCN() + " parqueos disponibles en Central").build();
                com.twilio.twiml.messaging.Message message = new com.twilio.twiml.messaging.Message.Builder().body(body).build();
                MessagingResponse twiml = new MessagingResponse.Builder().message(message).build(); 
                                return twiml.toXml();
                }
                if(req.queryParams("Body").equalsIgnoreCase("SN")){
               Body body = new Body.Builder(readSN() + " parqueos disponibles en Sede Norte").build();
                com.twilio.twiml.messaging.Message message = new com.twilio.twiml.messaging.Message.Builder().body(body).build();
                MessagingResponse twiml = new MessagingResponse.Builder().message(message).build(); 
                                return twiml.toXml();

                }
                else{
                    Body body = new Body.Builder("Envia *SN* para saber los parqueos en Sede Norte y *CN* para Central").build();
                com.twilio.twiml.messaging.Message message = new com.twilio.twiml.messaging.Message.Builder().body(body).build();
                MessagingResponse twiml = new MessagingResponse.Builder().message(message).build(); 
                System.out.println(req.queryParams("Body") + " de " + req.queryParams("From"));
                                return twiml.toXml();
                }
                
            });
       
       
         
    }
}
