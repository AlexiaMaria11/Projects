<html>
<body>
<?php
$servername = "192.168.0.4";
$username = "AOprita";//se va trece user-ul personal
$password = "ale11032004";//se va trece parola personala
$dbname = "AOprita";//numele bazei de date, la voi este acelasi ca user-ul

// creare conexiune
$conn = new mysqli($servername, $username, $password, $dbname);
// verificare conexiune cu baza de date
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

//Introduceti datele din formular in tabela date
$sql = "INSERT INTO parere (Nume, Email, Mesajul tau) 
VALUES ('".$_POST["Nume"]."', '".$_POST["Email"]."', '".$_POST["Mesajul tau"]."')";

if ($conn->query($sql) === TRUE) {
    echo "New record created successfully";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

//afisati toate datele existente in tabela elev
$sql = "SELECT * FROM parere";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // se afiseaza datele de pe fiecare rand din tabela
    while($row = $result->fetch_assoc()) {
        echo " - Părere " . $row["Nume"]. " " . $row["Email"]. " " . $row["Mesajul tau"]. "<br>";
    }
} else {
    echo "0 results";
}

$conn->close();
?>
</body>
</html>