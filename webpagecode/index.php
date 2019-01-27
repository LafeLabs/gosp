<!doctype html>
<html  lang="en">
<head>
<meta charset="utf-8"> 
<title>Site Builder</title>
<!-- 
PUBLIC DOMAIN, NO COPYRIGHTS, NO PATENTS.
-->
<!--Stop Google:-->
<META NAME="robots" CONTENT="noindex,nofollow">
</head>
<body>
<a href = "siteeditor.php" style = "font-family:helvetica;position:absolute;right:0px;top:0px;z-index:2">EDIT</a>
<?php

    echo file_get_contents("html/index.txt");

?>
</body>
</html>