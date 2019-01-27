 <!doctype html>
<html>
<head>
 <!-- 
PUBLIC DOMAIN, NO COPYRIGHTS, NO PATENTS.
-->
<!--Stop Google:-->
<META NAME="robots" CONTENT="noindex,nofollow">
<script src="https://cdnjs.cloudflare.com/ajax/libs/ace/1.2.6/ace.js" type="text/javascript" charset="utf-8"></script>
<title>Site Editor</title>
</head>
<body>

<a id = "indexlink" href = "index.php">PAGE</a>

<div id="maineditor" contenteditable="true" spellcheck="false"></div>


<script>


editor = ace.edit("maineditor");
editor.setTheme("ace/theme/cobalt");
editor.getSession().setMode("ace/mode/html");
editor.getSession().setUseWrapMode(true);
editor.$blockScrolling = Infinity;

var httpc = new XMLHttpRequest();
httpc.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        filedata = this.responseText;
        editor.setValue(filedata);
    }
};
httpc.open("GET", "fileloader.php?filename=html/index.txt", true);
httpc.send();


document.getElementById("maineditor").onkeyup = function(){
    data = encodeURIComponent(editor.getSession().getValue());
    var httpc = new XMLHttpRequest();
    var url = "filesaver.php";        
    httpc.open("POST", url, true);
    httpc.setRequestHeader("Content-Type", "application/x-www-form-urlencoded;charset=utf-8");
    httpc.send("data="+data+"&filename=html/index.txt");//send text to filesaver.php
}


</script>
<style>
body{
    background-color:#d0d0d0;
}
.html{
    color:#0000ff;
}

#maineditor{
    position:absolute;
    left:2em;
    top:5em;
    bottom:1em;
    right:2em;
    font-size:18px;
    border-color:blue;
    border:solid;
    border-width:5px;
}
#indexlink{
    position:absolute;
    right:0px;
    top:0px;
    font-family:helvetica;
}


</style>

</body>
</html>