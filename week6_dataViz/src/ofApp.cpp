#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    string filePath = "SalesJan2009.csv";
    ofFile file(filePath);
    
    if(!file.exists()){
        ofLogError("The file " + filePath + " is missing");
    }
    ofBuffer buffer(file);
    for (ofBuffer::Line it = buffer.getLines().begin(), end = buffer.getLines().end(); it != end; ++it) {
        string line = *it;
        //Split line into strings
        vector<string> words = ofSplitString(line, ",");
        cout << words.size() << endl;
        //Store strings into a custom container
        if (words.size()>11) {
            /*
            Transaction_date,0
            Product,1
            Price,2
            Payment_Type,3
            Name,4
            City,5
            State,6
            Country,7
            Account_Created,8
            Last_Login,9
            Latitude,10
            Longitude,11
            //*/
            
            creditCard newCard;
            newCard.cardType = words[3];
            newCard.city = words[5];
            newCard.country = words[7];
            
            string time = ofSplitString(words[0], " ")[1];
            vector<string> t = ofSplitString(time, ":");
            int hour = ofToInt(t[0]);
            int minute = ofToInt(t[1]);
            
            newCard.time = hour + minute/60.0;
            newCard.date = words[0];
            newCard.name = words[4];
            newCard.price = words[2];
            newCard.product = words[1];
            newCard.state = words[6];
            newCard.geoPos =ofVec2f(ofToFloat(words[10]), ofToFloat(words[11]));
            
            cards.push_back(newCard);
            
            cardBrand[newCard.cardType]+=1;
//            cardType.push_back(words[3]);
//            city.push_back(words[5]);
//            geoPos.push_back(ofVec2f(ofToFloat(words[10]), ofToFloat(words[11])));
        }
    }
    for (auto& brand:cardBrand) {
        cout << brand.first << "  " << brand.second << endl;
    }
    
    map.load("worldMap.jpg");

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

//    ofBackground(0);
    ofSetColor(255, 40);
    map.draw(0, 0, ofGetWidth(), ofGetHeight());
  
    for(int i = 0; i < cards.size(); i++){
    
        float x = ofMap(cards[i].geoPos.y, -180, 180, 0, ofGetWidth());
        float y = ofMap(cards[i].geoPos.x, -90, 90, ofGetHeight(),0);
        
        
        
//        if (cards[i].time > 22 || cards[i].time < 6) {
//        ofSetColor(ofColor::red);
//        }else{
//        ofSetColor(0,10);
//        }

        ofSetColor(ofColor::red, ofMap(cards[i].time, 0, 24, 0, 255));
        if(cards[i].cardType == "Amex") {
                ofSetColor(ofColor::fuchsia);
        }else if(cards[i].cardType == "Diners"){
                ofSetColor(ofColor::greenYellow);
        }else if(cards[i].cardType == "Mastercard"){
                ofSetColor(ofColor::indigo);
        }else if(cards[i].cardType == "Visa"){
                ofSetColor(ofColor::red);
        }
        

        
        ofDrawCircle(x, y, 5);// ofToFloat(cards[i].price)/100);
//        ofSetColor(0);
        
//        ofDrawBitmapString(cards[i].city, x, y);
        
        ofDrawBitmapStringHighlight("Amex",100,40,ofColor::fuchsia,ofColor::black);
        ofDrawBitmapStringHighlight("Diners",100,60,ofColor::greenYellow,ofColor::black);
        ofDrawBitmapStringHighlight("Mastercard",100,80,ofColor::indigo,ofColor::black);
        ofDrawBitmapStringHighlight("Visa",100,100,ofColor::red,ofColor::black);
        
        
        
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
