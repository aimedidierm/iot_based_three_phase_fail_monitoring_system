<?php
require 'php-includes/connect.php';
if(isset($_POST['l1'])&&($_POST['l2'])&&($_POST['l3'])){
    $l1 = $_POST['l1'];
    $l2 = $_POST['l2'];
    $l3 = $_POST['l3'];
    $sql ="INSERT INTO status (l1,l2,l3) VALUES (?,?,?)";
    $stm = $db->prepare($sql);
    if ($stm->execute(array($l1,$l2,$l3))) {
        //
    }
}
?>