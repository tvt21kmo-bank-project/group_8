-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: projekti
-- ------------------------------------------------------
-- Server version	8.0.23

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `asiakas`
--

DROP TABLE IF EXISTS `asiakas`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas` (
  `idasiakas` int NOT NULL AUTO_INCREMENT,
  `nimi` varchar(45) NOT NULL,
  `osoite` varchar(45) NOT NULL,
  `puhelinnumero` varchar(45) NOT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Simo','Merikosken sillan alla','1234567890');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_pankkitili`
--

DROP TABLE IF EXISTS `asiakas_pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_pankkitili` (
  `tilinumero` int NOT NULL,
  `idasiakas` int NOT NULL,
  PRIMARY KEY (`tilinumero`,`idasiakas`),
  KEY `fk_assiakas_pankkitili_asiakas1_idx` (`idasiakas`),
  CONSTRAINT `fk_assiakas_pankkitili_asiakas1` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_assiakas_pankkitili_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_pankkitili`
--

LOCK TABLES `asiakas_pankkitili` WRITE;
/*!40000 ALTER TABLE `asiakas_pankkitili` DISABLE KEYS */;
INSERT INTO `asiakas_pankkitili` VALUES (1,1),(2,1);
/*!40000 ALTER TABLE `asiakas_pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkikortti`
--

DROP TABLE IF EXISTS `pankkikortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkikortti` (
  `korttinumero` int NOT NULL AUTO_INCREMENT,
  `pin` varchar(60) DEFAULT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT NULL,
  `idasiakas` int DEFAULT NULL,
  PRIMARY KEY (`korttinumero`,`tilinumero`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
INSERT INTO `pankkikortti` VALUES (4,'$2a$10$t9gCnLquUPWrvn5L/PBiVehWZomUizInOWVHNjooW6yS60vf90g.O',0,1,0,1),(5,'$2a$10$jzdoDp3ey2rfF8JOLYkyLOmNjbyznOpmmn7X7uM3d6o06PiFQ1phG',1,2,0,1);
/*!40000 ALTER TABLE `pankkikortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkitili`
--

DROP TABLE IF EXISTS `pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkitili` (
  `tilinumero` int NOT NULL AUTO_INCREMENT,
  `saldo` double DEFAULT NULL,
  `credit` double DEFAULT NULL,
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (1,12,NULL),(2,500,1500);
/*!40000 ALTER TABLE `pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `tapahtumat`
--

DROP TABLE IF EXISTS `tapahtumat`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `tapahtumat` (
  `idtapahtumat` int NOT NULL AUTO_INCREMENT,
  `korttinumero` int NOT NULL,
  `tilinumero` int NOT NULL,
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` double DEFAULT NULL,
  `credit` tinyint NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (1,1,1,'2058-01-19 03:14:07','Automaattinosto',-80,0);
/*!40000 ALTER TABLE `tapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'projekti'
--
/*!50003 DROP PROCEDURE IF EXISTS `nostaRahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `nostaRahaa`(
	IN korttinro INT, 
    IN summa double,
    IN luotto tinyint)
BEGIN
DECLARE uusiSaldo double DEFAULT 0;
DECLARE tilinro int DEFAULT 0;

/* Haetaan paikalliseen muuttujaan pankkikorttia vastaava tilinumero */
SELECT tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=korttinro;

/* Haetaan paikalliseen muuttujaan pankkikorttia vastaavan käyttäjän valitseman credit- tai debit-tilin saldo */
IF luotto = 1 THEN
	SELECT credit INTO uusiSaldo FROM pankkitili WHERE tilinumero=tilinro;
ELSE
	SELECT saldo INTO uusiSaldo FROM pankkitili WHERE tilinumero=tilinro;
END IF;

/* Lasketaan nostotahtuman aiheuttama muutos tilin saldoon */
SET uusiSaldo = uusiSaldo - summa;

/* Päivetään tietokantaan pankkitin saldo */
IF luotto = 1 THEN
	UPDATE pankkitili SET credit=uusiSaldo WHERE tilinumero=tilinro;
ELSE
	UPDATE pankkitili SET saldo=uusiSaldo WHERE tilinumero=tilinro;
END IF;

/* Lisätään tahpahtuman tiedot tietokantaan */
INSERT INTO tapahtumat VALUES(NULL , korttinro, tilinro, CURRENT_TIMESTAMP(), 'Automaattinosto', summa, luotto);

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talletaRahaa` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `talletaRahaa`(
	IN korttinro INT, 
    IN summa double)
BEGIN
DECLARE uusiSaldo double DEFAULT 0;
DECLARE tilinro int DEFAULT 0;

/* Haetaan paikallisiin muuttujiin pankkikorttia vastaava tilinumero ja debit-tilin saldo */
SELECT tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=korttinro;
SELECT saldo INTO uusiSaldo FROM pankkitili WHERE tilinumero=tilinro;

/* Lisätään talletettu rahasumma tilin saldoon ja päivetään uusi saldo tietokantaan */
SET uusiSaldo = uusiSaldo + summa;
UPDATE pankkitili SET saldo=uusiSaldo WHERE tilinumero=tilinro;

/* Lisätään tahpahtuman tiedot tietokantaan */
INSERT INTO tapahtumat VALUES(NULL , korttinro, tilinro, CURRENT_TIMESTAMP(), 'Automaattitalletus', summa, 0);

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tarkistaSaldo` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tarkistaSaldo`(
	IN korttinro INT, 
    IN summa double,
    IN luotto tinyint,
    OUT saldoOk boolean)
sk:BEGIN
DECLARE kate double DEFAULT 0;

/* Luottokorttia käytettäessä katteen tarkastusta ei ole tarpeen tehdä  */
IF luotto = 1 THEN
	SET saldoOk = true;
    LEAVE sk;
ELSE
/* Haetaan paikalliseen muutujaan pankkikorttia vastaavan debit-pankkitilin saldo */
SELECT saldo INTO kate FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=korttinro;

/* Verrataan riittääkö kate nostoon ja palautetaan vertailun tulos boolean-arvona */
IF kate >= summa THEN
	SET saldoOk = true;
ELSEIF kate < summa THEN
	SET saldoOk = false;
END IF;
END IF;
    
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-11-24 17:42:51
