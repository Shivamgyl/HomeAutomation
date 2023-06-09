var ss = SpreadsheetApp.openByUrl("https://docs.google.com/spreadsheets/d/1i4KpDbraxF_qWTQroXsjVsCKGqyYCuQg-t6bUr8dFD4/edit#gid=0");
var sheet = ss.getSheetByName("Daily_Attendance");

function doGet(e){
  var action = e.parameter.action;
  if(action == "in")
    return inTime(e);
  if(action == "out")
    return outTime(e);
  
}

function doPost(e){
  var action = e.parameter.action;
  if(action == "in")
    return inTime(e);
  if(action == "out")
    return outTime(e);
  
}

function inTime(e){
  var id = e.parameter.id;
  var values = sheet.getRange(2,1,sheet.getLastRow(),1).getValues();

  for(var i =0 ; i<values.length ; i++){
    if(values[i][0] == id){
      i=i+2;
      var in_time = Utilities.formatDate(new Date(),"IST", "HH:mm:ss");
      sheet.getRange(i,3).setValue(in_time);
      return ContentService.createTextOutput("Thank You ! your in time is"+in_time).setMimeType(ContentService.MimeType.TEXT);
    }
  }
  return ContentService.createTextOutput("ID not found").setMimeType(ContentService.MimeType.TEXT);

    }
  
  function outTime(e){
  var id = e.parameter.id;
  var values = sheet.getRange(2,1,sheet.getLastRow(),1).getValues();

  for(var i =0 ; i<values.length ; i++){
    if(values[i][0] == id){
      i=i+2;
      var out_time = Utilities.formatDate(new Date(),"IST", "HH:mm:ss");
      sheet.getRange(i,4).setValue(out_time);
      return ContentService.createTextOutput("Thank You ! your out time is"+out_time).setMimeType(ContentService.MimeType.TEXT);
    }
  }
  return ContentService.createTextOutput("ID not found").setMimeType(ContentService.MimeType.TEXT);
  
    }
 

