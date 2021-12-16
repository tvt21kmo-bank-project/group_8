<<<<<<< Updated upstream:pankkiautomaatti_tietokantadump.sql
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: saulindb
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
  `puhelinnro` varchar(45) NOT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Sauli Partanen','Uusikatu','89455497'),(2,'Samuli Salmi','Rajakylä','708345543'),(3,'Tero Vähäsarja','Merikosken sillan alla','703454537');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_pankkitili`
--

DROP TABLE IF EXISTS `asiakas_pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_pankkitili` (
  `idasiakas` int NOT NULL,
  `tilinumero` int NOT NULL,
  PRIMARY KEY (`idasiakas`,`tilinumero`),
  KEY `fk_asiakas_pankkitili_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_asiakas_pankkitili_asiakas` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_asiakas_pankkitili_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_pankkitili`
--

LOCK TABLES `asiakas_pankkitili` WRITE;
/*!40000 ALTER TABLE `asiakas_pankkitili` DISABLE KEYS */;
INSERT INTO `asiakas_pankkitili` VALUES (1,3),(2,4),(3,5);
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
  `pin` varchar(60) NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT '0',
  `idasiakas` int NOT NULL,
  PRIMARY KEY (`korttinumero`,`tilinumero`,`idasiakas`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  KEY `fk_pankkikortti_asiakas1_idx` (`idasiakas`),
  CONSTRAINT `fk_pankkikortti_asiakas1` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
INSERT INTO `pankkikortti` VALUES (4,'$2a$10$20nA3M5VqE02IdtJ2XuFW.TdDcOEb4.d94njTYeGjZZuRJiGpK2VK',1,3,0,1),(5,'$2a$10$0SQimzxJFwroAczeIVbPKO7o2.SQ9.3CgqCWG5hhdEfH80s1/UbXO',0,4,0,2),(7,'$2a$10$19fyUcYem.TQ0z.QCYHKL.daox1WdgAjRxuHtANBhEIzmC713lPHS',1,5,0,3),(8,'$2a$10$UPtVJWAXluj9wwYwqUK.DeJ6nzGtrvwgsI9cRyFS6zc9kpvLv8nqS',1,3,0,2);
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
  `saldo` double NOT NULL,
  `creditsaldo` double DEFAULT '0',
  `luottoraja` double DEFAULT '0',
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (3,4500,1500,15000),(4,120,NULL,NULL),(5,163.85,-609,2000);
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
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` double NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `maksaja_saaja` varchar(45) NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=61 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (58,'2021-12-12 14:05:13','Talletus',1,0,5,'Pankkikortti#7'),(59,'2021-12-12 17:24:10','Talletus',200,0,5,'Pankkikortti#7'),(60,'2021-12-12 17:25:00','Nosto tililtä',-40,0,5,'Pankkikortti#7');
/*!40000 ALTER TABLE `tapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'saulindb'
--
/*!50003 DROP PROCEDURE IF EXISTS `credit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_tilisiirto`(
IN id1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT creditraja FLOAT)
BEGIN
  DECLARE test2,tilinumero1 INT DEFAULT 0;
  START TRANSACTION;
    SELECT pankkikortti.tilinumero INTO tilinumero1 FROM pankkikortti WHERE pankkikortti.korttinumero = id1; 
    SELECT luottoraja INTO creditraja FROM pankkitili WHERE tilinumero = tilinumero1;
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 1 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=tilinumero2;
				UPDATE pankkitili SET luottoraja=luottoraja-summa WHERE tilinumero=tilinumero1;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '1');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '1');
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
  
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 0 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
				UPDATE pankkitili SET luottoraja=luottoraja-summa WHERE tilinumero=tilinumero1;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '1');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '0');
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT luottoraja INTO creditraja FROM pankkitili WHERE tilinumero = tilinumero1;
	SELECT creditraja;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `credit_to_debit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_to_debit`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=id1;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=id1;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '0');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'siirto', summa, id1, '1');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_tilisiirto`(
IN id1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT saldoUlos FLOAT)
BEGIN
  DECLARE test2,tilinumero1 INT DEFAULT 0;
  START TRANSACTION;
    SELECT pankkikortti.tilinumero INTO tilinumero1 FROM pankkikortti WHERE pankkikortti.korttinumero = id1; 
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 1) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '0');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '1');
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
  
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 0) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', -summa, tilinumero1, '0');
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'tilisiirto', summa, tilinumero2, '0');
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT saldo INTO saldoUlos FROM pankkitili WHERE tilinumero = tilinumero1;
    SELECT saldoUlos;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_to_credit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_to_credit`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=id1 AND saldo>=summa;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=id1;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'siirto', summa, id1, '0');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '1');
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `otto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `otto`(IN id1 INT, IN summa DOUBLE, IN luotto TINYINT)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  DECLARE m_s varchar(20) DEFAULT 'Pankkikortti#';
   DECLARE tilinro int DEFAULT 0;
  START TRANSACTION;
  SELECT pankkitili.tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=id1;
  IF luotto = 1 THEN
	UPDATE pankkitili SET credit=credit-summa WHERE tilinumero=tilinro;
ELSE
	UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinro;
END IF;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT; 
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja) VALUES(NULL, NOW(), 'Nosto tililtä', -summa, 0, tilinro, CONCAT(m_s,id1));
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pin_Katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pin_Katsaus`(
IN id1 INT,
IN pin TINYINT,
OUT laskuri INT
)
BEGIN
IF (pin = 1) THEN UPDATE pankkikortti SET pankkikortti.pinVaarin=0 WHERE korttinumero=id1;
ELSE IF (pin = 0) THEN
    UPDATE pankkikortti SET pankkikortti.pinVaarin=pankkikortti.pinVaarin+1 WHERE korttinumero=id1;
END IF;
END IF;
IF (laskuri > 2) THEN DELETE FROM pankkikortti WHERE korttinumero = id1; 
END IF;
SELECT pinVaarin INTO laskuri from pankkikortti WHERE korttinumero = id1;
SELECT laskuri;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `saldo_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `saldo_katsaus`(IN id1 INT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO credit;
SELECT pankkikortti.tilinumero FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO id2;
IF (credit = 1) THEN SELECT pankkitili.saldo, pankkitili.creditsaldo, luottoraja, nimi FROM pankkitili JOIN asiakas_pankkitili ON asiakas_pankkitili.tilinumero=pankkitili.tilinumero JOIN asiakas ON asiakas.idasiakas=asiakas_pankkitili.idasiakas WHERE pankkitili.tilinumero = id2;
ELSE SELECT pankkitili.saldo, nimi FROM pankkitili JOIN asiakas_pankkitili ON asiakas_pankkitili.tilinumero=pankkitili.tilinumero JOIN asiakas ON asiakas.idasiakas=asiakas_pankkitili.idasiakas WHERE pankkitili.tilinumero = id2; 
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talletus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `talletus`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  DECLARE tilinro int DEFAULT 0;
  DECLARE m_s varchar(20) DEFAULT 'Pankkikortti#';
  SELECT pankkitili.tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=id1;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinro;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja) VALUES(NULL, NOW(), 'Talletus', summa, 0, tilinro, CONCAT(m_s,id1));
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tilitapahtuma_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tilitapahtuma_katsaus`(
IN id1 INT,
IN luotto TINYINT,
IN alkaenRivilta INT
)
BEGIN
	DECLARE id2 INT;
    SELECT tilinumero INTO id2 FROM pankkikortti WHERE korttinumero = id1;
	SELECT * FROM tapahtumat WHERE tilinumero=id2 AND credit=luotto ORDER BY aikaleima DESC LIMIT alkaenRivilta, 10;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tili_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tili_katsaus`(
IN id1 INT,
OUT omistaja VARCHAR(20),
OUT creditSaldo FLOAT,
OUT debitSaldo FLOAT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit INTO credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT pankkikortti.tilinumero INTO id2 FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT nimi INTO omistaja FROM asiakas JOIN asiakas_pankkitili ON asiakas_pankkitili.idasiakas = asiakas.idasiakas JOIN pankkitili ON pankkitili.tilinumero = asiakas_pankkitili.tilinumero WHERE pankkitili.tilinumero = id2;
SELECT pankkitili.saldo INTO debitSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2; 
SELECT pankkitili.creditsaldo INTO creditSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2;
IF (credit = 1) THEN SELECT omistaja, debitSaldo, creditSaldo;
ELSE SELECT omistaja, debitSaldo;
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

-- Dump completed on 2021-12-12 17:39:07
=======
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: 127.0.0.1    Database: pankkisimulaattori
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
  `puhelinnro` varchar(45) NOT NULL,
  PRIMARY KEY (`idasiakas`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas`
--

LOCK TABLES `asiakas` WRITE;
/*!40000 ALTER TABLE `asiakas` DISABLE KEYS */;
INSERT INTO `asiakas` VALUES (1,'Sauli Partanen','Uusikatu','89455497'),(2,'Samuli Salmi','Rajakylä','708345543'),(3,'Tero Vähäsarja','Merikosken sillan alla','703454537');
/*!40000 ALTER TABLE `asiakas` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `asiakas_pankkitili`
--

DROP TABLE IF EXISTS `asiakas_pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `asiakas_pankkitili` (
  `idasiakas` int NOT NULL,
  `tilinumero` int NOT NULL,
  PRIMARY KEY (`idasiakas`,`tilinumero`),
  KEY `fk_asiakas_pankkitili_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_asiakas_pankkitili_asiakas` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_asiakas_pankkitili_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `asiakas_pankkitili`
--

LOCK TABLES `asiakas_pankkitili` WRITE;
/*!40000 ALTER TABLE `asiakas_pankkitili` DISABLE KEYS */;
INSERT INTO `asiakas_pankkitili` VALUES (1,3),(2,4),(3,5);
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
  `pin` varchar(60) NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT '0',
  `idasiakas` int NOT NULL,
  PRIMARY KEY (`korttinumero`,`tilinumero`,`idasiakas`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  KEY `fk_pankkikortti_asiakas1_idx` (`idasiakas`),
  CONSTRAINT `fk_pankkikortti_asiakas1` FOREIGN KEY (`idasiakas`) REFERENCES `asiakas` (`idasiakas`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
INSERT INTO `pankkikortti` VALUES (4,'$2a$10$20nA3M5VqE02IdtJ2XuFW.TdDcOEb4.d94njTYeGjZZuRJiGpK2VK',1,3,0,1),(5,'$2a$10$0SQimzxJFwroAczeIVbPKO7o2.SQ9.3CgqCWG5hhdEfH80s1/UbXO',0,4,0,2),(7,'$2a$10$19fyUcYem.TQ0z.QCYHKL.daox1WdgAjRxuHtANBhEIzmC713lPHS',1,5,0,3),(8,'$2a$10$UPtVJWAXluj9wwYwqUK.DeJ6nzGtrvwgsI9cRyFS6zc9kpvLv8nqS',1,3,0,2);
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
  `saldo` double NOT NULL,
  `creditsaldo` double DEFAULT '0',
  `luottoraja` double DEFAULT '0',
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (3,8265,1883,14811),(4,5671,NULL,NULL),(5,8259.85,-211,2000);
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
  `aikaleima` datetime NOT NULL,
  `tapahtuma` varchar(45) NOT NULL,
  `summa` double NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `maksaja_saaja` varchar(45) NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=384 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (58,'2021-12-12 14:05:13','Talletus',1,0,5,'Pankkikortti#7'),(59,'2021-12-12 17:24:10','Talletus',200,0,5,'Pankkikortti#7'),(60,'2021-12-12 17:25:00','Nosto tililtä',-40,0,5,'Pankkikortti#7'),(61,'2021-12-12 20:07:56','Nosto tililtä',-500,0,3,'Pankkikortti#4'),(62,'2021-12-12 20:08:16','Talletus',125,0,3,'Pankkikortti#4'),(63,'2021-12-12 20:09:10','Nosto tililtä',-20,0,4,'Pankkikortti#5'),(64,'2021-12-13 14:24:19','tilisiirto',0,-6,3,'4'),(65,'2021-12-13 14:25:19','tilisiirto',0,-6,3,'4'),(66,'2021-12-13 14:25:19','tilisiirto',1,6,5,'7'),(67,'2021-12-13 14:25:58','tilisiirto',0,-5,3,'4'),(68,'2021-12-13 14:25:58','tilisiirto',1,5,5,'7'),(69,'2021-12-13 14:30:13','tilisiirto',0,-9,3,'4'),(70,'2021-12-13 14:30:13','tilisiirto',1,9,5,'7'),(71,'2021-12-13 21:56:46','tilisiirto',0,-9,4,'tilille5'),(72,'2021-12-13 21:56:46','tilisiirto',1,9,5,'tililtä4'),(73,'2021-12-13 21:56:54','tilisiirto',0,-1,4,'tilille5'),(74,'2021-12-13 21:56:54','tilisiirto',1,1,5,'tililtä4'),(75,'2021-12-13 21:56:58','tilisiirto',0,-10,4,'tilille5'),(76,'2021-12-13 21:56:58','tilisiirto',1,10,5,'tililtä4'),(77,'2021-12-13 22:06:06','tilisiirto',0,-10,4,'tilille3'),(78,'2021-12-13 22:06:06','tilisiirto',1,10,3,'tililtä4'),(79,'2021-12-13 22:06:19','tilisiirto',0,-10,4,'tilille3'),(80,'2021-12-13 22:06:19','tilisiirto',1,10,3,'tililtä4'),(81,'2021-12-13 22:06:20','tilisiirto',0,-10,4,'tilille3'),(82,'2021-12-13 22:06:20','tilisiirto',1,10,3,'tililtä4'),(83,'2021-12-13 22:13:45','tilisiirto',0,-2,3,'tilille3'),(84,'2021-12-13 22:13:45','tilisiirto',0,2,5,'tililtä5'),(85,'2021-12-13 22:22:52','tilisiirto',0,-10,4,'tilille3'),(86,'2021-12-13 22:22:52','tilisiirto',1,10,3,'tililtä4'),(87,'2021-12-13 22:23:24','tilisiirto',0,-10,4,'tilille3'),(88,'2021-12-13 22:23:24','tilisiirto',1,10,3,'tililtä4'),(89,'2021-12-13 22:25:36','tilisiirto',0,-10,4,'tilille3'),(90,'2021-12-13 22:25:36','tilisiirto',1,10,3,'tililtä4'),(91,'2021-12-13 22:29:21','tilisiirto',0,0,4,'tilille3'),(92,'2021-12-13 22:29:21','tilisiirto',1,0,3,'tililtä4'),(93,'2021-12-13 22:29:22','tilisiirto',0,0,4,'tilille3'),(94,'2021-12-13 22:29:22','tilisiirto',1,0,3,'tililtä4'),(95,'2021-12-13 22:29:23','tilisiirto',0,0,4,'tilille3'),(96,'2021-12-13 22:29:23','tilisiirto',1,0,3,'tililtä4'),(97,'2021-12-13 22:30:50','tilisiirto',0,-5,3,'tilille3'),(98,'2021-12-13 22:30:50','tilisiirto',0,5,5,'tililtä5'),(99,'2021-12-13 22:31:25','tilisiirto',0,-2,3,'tilille3'),(100,'2021-12-13 22:31:25','tilisiirto',0,2,5,'tililtä5'),(101,'2021-12-13 23:02:30','tilisiirto',0,-2,3,'tilille3'),(102,'2021-12-13 23:02:30','tilisiirto',0,2,5,'tililtä5'),(103,'2021-12-13 23:03:55','tilisiirto',0,-36,3,'tilille3'),(104,'2021-12-13 23:03:55','tilisiirto',0,36,4,'tililtä4'),(105,'2021-12-13 23:04:49','tilisiirto',0,-2,3,'tilille3'),(106,'2021-12-13 23:04:49','tilisiirto',0,2,5,'tililtä5'),(107,'2021-12-13 23:07:54','tilisiirto',0,-5,3,'tilille3'),(108,'2021-12-13 23:07:54','tilisiirto',0,5,5,'tililtä5'),(109,'2021-12-13 23:14:14','tilisiirto',0,-5,3,'tilille3'),(110,'2021-12-13 23:14:14','tilisiirto',0,5,5,'tililtä5'),(111,'2021-12-13 23:14:49','tilisiirto',0,-5,3,'tilille3'),(112,'2021-12-13 23:14:49','tilisiirto',0,5,5,'tililtä5'),(113,'2021-12-13 23:16:20','tilisiirto',0,-12,3,'tilille3'),(114,'2021-12-13 23:16:20','tilisiirto',0,12,5,'tililtä5'),(115,'2021-12-13 23:16:49','tilisiirto',0,-10,3,'tilille3'),(116,'2021-12-13 23:16:49','tilisiirto',0,10,5,'tililtä5'),(117,'2021-12-13 23:16:56','tilisiirto',0,-10,3,'tilille3'),(118,'2021-12-13 23:16:56','tilisiirto',0,10,5,'tililtä5'),(119,'2021-12-13 23:16:59','tilisiirto',0,-10,3,'tilille3'),(120,'2021-12-13 23:16:59','tilisiirto',0,10,5,'tililtä5'),(121,'2021-12-13 23:20:50','tilisiirto',-2,0,3,'tilille3'),(122,'2021-12-13 23:20:50','tilisiirto',2,0,5,'tililtä5'),(123,'2021-12-13 23:20:52','tilisiirto',-2,0,3,'tilille3'),(124,'2021-12-13 23:20:52','tilisiirto',2,0,5,'tililtä5'),(125,'2021-12-13 23:20:54','tilisiirto',-2,0,3,'tilille3'),(126,'2021-12-13 23:20:54','tilisiirto',2,0,5,'tililtä5'),(127,'2021-12-13 23:20:56','tilisiirto',-5,0,3,'tilille3'),(128,'2021-12-13 23:20:56','tilisiirto',5,0,5,'tililtä5'),(129,'2021-12-13 23:24:36','tilisiirto',-10,1,3,'tilille5'),(130,'2021-12-13 23:24:36','tilisiirto',10,1,5,'tililtä3'),(131,'2021-12-13 23:24:46','tilisiirto',-10,1,3,'tilille5'),(132,'2021-12-13 23:24:46','tilisiirto',10,1,5,'tililtä3'),(133,'2021-12-13 23:24:47','tilisiirto',-10,1,3,'tilille5'),(134,'2021-12-13 23:24:47','tilisiirto',10,1,5,'tililtä3'),(135,'2021-12-13 23:24:48','tilisiirto',-10,1,3,'tilille5'),(136,'2021-12-13 23:24:48','tilisiirto',10,1,5,'tililtä3'),(137,'2021-12-13 23:27:37','tilisiirto',-10,1,3,'tilille5'),(138,'2021-12-13 23:27:37','tilisiirto',10,1,5,'tililtä3'),(139,'2021-12-13 23:27:40','tilisiirto',-10,1,3,'tilille5'),(140,'2021-12-13 23:27:40','tilisiirto',10,1,5,'tililtä3'),(141,'2021-12-13 23:27:41','tilisiirto',-10,1,3,'tilille5'),(142,'2021-12-13 23:27:41','tilisiirto',10,1,5,'tililtä3'),(143,'2021-12-13 23:27:42','tilisiirto',-10,1,3,'tilille5'),(144,'2021-12-13 23:27:42','tilisiirto',10,1,5,'tililtä3'),(145,'2021-12-13 23:29:08','tilisiirto',-29,1,3,'tilille5'),(146,'2021-12-13 23:29:08','tilisiirto',29,1,5,'tililtä3'),(147,'2021-12-13 23:33:33','tilisiirto',-10,1,3,'tilille5'),(148,'2021-12-13 23:33:33','tilisiirto',10,1,5,'tililtä3'),(149,'2021-12-13 23:34:52','tilisiirto',-5,1,3,'tilille5'),(150,'2021-12-13 23:34:52','tilisiirto',5,1,5,'tililtä3'),(151,'2021-12-13 23:34:58','tilisiirto',-5,1,3,'tilille5'),(152,'2021-12-13 23:34:58','tilisiirto',5,1,5,'tililtä3'),(153,'2021-12-13 23:35:44','tilisiirto',-15,1,3,'tilille5'),(154,'2021-12-13 23:35:44','tilisiirto',15,1,5,'tililtä3'),(155,'2021-12-13 23:35:50','tilisiirto',-20,1,3,'tilille5'),(156,'2021-12-13 23:35:50','tilisiirto',20,1,5,'tililtä3'),(157,'2021-12-13 23:35:54','tilisiirto',-2,1,3,'tilille5'),(158,'2021-12-13 23:35:54','tilisiirto',2,1,5,'tililtä3'),(159,'2021-12-13 23:35:59','tilisiirto',-8,1,3,'tilille5'),(160,'2021-12-13 23:35:59','tilisiirto',8,1,5,'tililtä3'),(161,'2021-12-13 23:36:01','tilisiirto',-2,1,3,'tilille5'),(162,'2021-12-13 23:36:01','tilisiirto',2,1,5,'tililtä3'),(163,'2021-12-13 23:37:49','tilisiirto',-5,1,3,'tilille5'),(164,'2021-12-13 23:37:49','tilisiirto',5,1,5,'tililtä3'),(165,'2021-12-13 23:37:58','tilisiirto',-8,1,3,'tilille5'),(166,'2021-12-13 23:37:58','tilisiirto',8,1,5,'tililtä3'),(167,'2021-12-13 23:41:23','tilisiirto',-20,1,3,'tilille5'),(168,'2021-12-13 23:41:23','tilisiirto',20,1,5,'tililtä3'),(169,'2021-12-13 23:41:27','tilisiirto',-2,1,3,'tilille5'),(170,'2021-12-13 23:41:27','tilisiirto',2,1,5,'tililtä3'),(171,'2021-12-13 23:41:30','tilisiirto',-100,1,3,'tilille5'),(172,'2021-12-13 23:41:30','tilisiirto',100,1,5,'tililtä3'),(173,'2021-12-14 20:03:35','Nosto tililtä',-40,0,3,'Pankkikortti#4'),(174,'2021-12-14 20:03:51','Talletus',1000,0,3,'Pankkikortti#4'),(175,'2021-12-14 20:04:05','tilisiirto',-100,0,3,'tilille3'),(176,'2021-12-14 20:04:05','tilisiirto',100,0,5,'tililtä5'),(177,'2021-12-14 20:08:55','tilisiirto',-10,0,3,'tilille3'),(178,'2021-12-14 20:08:55','tilisiirto',10,0,5,'tililtä5'),(179,'2021-12-14 20:10:14','Talletus',2000,0,3,'Pankkikortti#4'),(180,'2021-12-14 20:10:32','tilisiirto',-5000,0,3,'tilille3'),(181,'2021-12-14 20:10:32','tilisiirto',5000,0,5,'tililtä5'),(182,'2021-12-14 20:13:33','tilisiirto',-5000,0,5,'tilille5'),(183,'2021-12-14 20:13:33','tilisiirto',5000,1,3,'tililtä3'),(184,'2021-12-14 20:13:48','tilisiirto',-10,0,5,'tilille5'),(185,'2021-12-14 20:13:48','tilisiirto',10,1,4,'tililtä4'),(186,'2021-12-14 20:13:59','tilisiirto',-10,0,5,'tilille5'),(188,'2021-12-14 20:20:03','tilisiirto',-10,0,5,'tilille5'),(189,'2021-12-14 20:20:03','tilisiirto',10,0,5,'tililtä5'),(190,'2021-12-14 20:20:26','tilisiirto',-10,0,5,'tilille5'),(191,'2021-12-14 20:20:26','tilisiirto',10,0,5,'tililtä5'),(192,'2021-12-14 20:21:31','tilisiirto',-12,0,5,'tilille5'),(193,'2021-12-14 20:21:31','tilisiirto',12,0,5,'tililtä5'),(194,'2021-12-14 20:26:05','Talletus',5000,0,4,'Pankkikortti#5'),(195,'2021-12-14 20:26:24','tilisiirto',-100,0,5,'tilille5'),(196,'2021-12-14 20:26:24','tilisiirto',100,1,3,'tililtä3'),(197,'2021-12-14 20:26:32','tilisiirto',-10,0,5,'tilille5'),(198,'2021-12-14 20:26:32','tilisiirto',10,1,5,'tililtä5'),(199,'2021-12-14 20:28:02','tilisiirto',-5,1,3,'tilille3'),(200,'2021-12-14 20:28:02','tilisiirto',5,0,3,'tililtä3'),(201,'2021-12-14 20:28:15','tilisiirto',-5,1,3,'tilille3'),(202,'2021-12-14 20:28:15','tilisiirto',5,1,3,'tililtä3'),(203,'2021-12-14 20:28:23','tilisiirto',-5,1,3,'tilille3'),(204,'2021-12-14 20:28:23','tilisiirto',5,0,3,'tililtä3'),(205,'2021-12-14 20:29:03','tilisiirto',-5,0,3,'tilille3'),(206,'2021-12-14 20:29:03','tilisiirto',5,0,3,'tililtä3'),(207,'2021-12-14 20:29:07','tilisiirto',-5,0,3,'tilille3'),(208,'2021-12-14 20:29:07','tilisiirto',5,1,3,'tililtä3'),(209,'2021-12-14 20:29:16','tilisiirto',-5,0,3,'tilille3'),(210,'2021-12-14 20:29:16','tilisiirto',5,1,3,'tililtä3'),(211,'2021-12-14 20:30:02','tilisiirto',-5,0,3,'tilille3'),(212,'2021-12-14 20:30:02','tilisiirto',5,0,3,'tililtä3'),(213,'2021-12-14 20:30:16','tilisiirto',-5,0,3,'tilille3'),(214,'2021-12-14 20:30:16','tilisiirto',5,1,3,'tililtä3'),(215,'2021-12-14 20:30:20','tilisiirto',-5,0,3,'tilille3'),(216,'2021-12-14 20:30:20','tilisiirto',5,1,3,'tililtä3'),(217,'2021-12-14 20:34:54','tilisiirto',-5000,1,3,'tilille3'),(218,'2021-12-14 20:34:54','tilisiirto',5000,0,5,'tililtä5'),(219,'2021-12-14 20:36:37','tilisiirto',-5000,0,3,'tilille3'),(220,'2021-12-14 20:36:37','tilisiirto',5000,0,5,'tililtä5'),(221,'2021-12-14 20:43:27','Talletus',3000,0,3,'Pankkikortti#4'),(222,'2021-12-14 20:43:35','Talletus',500,0,3,'Pankkikortti#4'),(223,'2021-12-14 20:44:23','Talletus',5000,0,3,'Pankkikortti#4'),(224,'2021-12-14 20:44:51','tilisiirto',-100,0,3,'tilille3'),(225,'2021-12-14 20:44:51','tilisiirto',100,0,5,'tililtä5'),(226,'2021-12-14 20:45:42','tilisiirto',-15,0,3,'tilille3'),(227,'2021-12-14 20:45:42','tilisiirto',15,0,5,'tililtä5'),(228,'2021-12-14 20:45:44','tilisiirto',-15,0,3,'tilille3'),(229,'2021-12-14 20:45:44','tilisiirto',15,0,4,'tililtä4'),(230,'2021-12-14 20:49:58','tilisiirto',-2000,0,5,'tilille5'),(231,'2021-12-14 20:49:58','tilisiirto',2000,0,3,'tililtä3'),(232,'2021-12-14 20:50:02','tilisiirto',-300,0,5,'tilille5'),(233,'2021-12-14 20:50:02','tilisiirto',300,1,3,'tililtä3'),(234,'2021-12-14 20:51:32','tilisiirto',-11,1,3,'tilille5'),(235,'2021-12-14 20:51:32','tilisiirto',11,0,5,'tililtä3'),(236,'2021-12-14 20:51:36','tilisiirto',-12,1,3,'tilille5'),(237,'2021-12-14 20:51:36','tilisiirto',12,1,5,'tililtä3'),(238,'2021-12-14 20:52:04','tilisiirto',-10,0,5,'tilille3'),(239,'2021-12-14 20:52:04','tilisiirto',10,0,3,'tililtä5'),(240,'2021-12-14 20:52:09','tilisiirto',-15,0,5,'tilille3'),(241,'2021-12-14 20:52:09','tilisiirto',15,0,3,'tililtä5'),(242,'2021-12-14 20:52:19','tilisiirto',-20,0,5,'tilille3'),(243,'2021-12-14 20:52:19','tilisiirto',20,1,3,'tililtä5'),(244,'2021-12-14 21:48:06','credit->debit',-10,1,3,'tilille3'),(245,'2021-12-14 21:48:40','credit->debit',-10,1,3,'tilille3'),(246,'2021-12-14 21:48:40','debit->credit',10,0,3,'tililtä3'),(247,'2021-12-14 21:56:23','tilisiirto',-10,0,4,'tilille5'),(248,'2021-12-14 21:56:23','tilisiirto',10,1,5,'tililtä4'),(249,'2021-12-14 21:56:24','tilisiirto',-10,0,4,'tilille5'),(250,'2021-12-14 21:56:24','tilisiirto',10,1,5,'tililtä4'),(251,'2021-12-14 21:56:25','tilisiirto',-10,0,4,'tilille5'),(252,'2021-12-14 21:56:25','tilisiirto',10,1,5,'tililtä4'),(253,'2021-12-14 21:57:58','credit->debit',-20,1,4,'tilille4'),(254,'2021-12-14 21:57:58','debit->credit',20,0,4,'tililtä4'),(255,'2021-12-14 21:57:59','credit->debit',-20,1,4,'tilille4'),(256,'2021-12-14 21:57:59','debit->credit',20,0,4,'tililtä4'),(257,'2021-12-14 21:58:00','credit->debit',-20,1,4,'tilille4'),(258,'2021-12-14 21:58:00','debit->credit',20,0,4,'tililtä4'),(259,'2021-12-14 21:58:01','credit->debit',-20,1,4,'tilille4'),(260,'2021-12-14 21:58:01','debit->credit',20,0,4,'tililtä4'),(261,'2021-12-14 21:58:03','credit->debit',-20,1,4,'tilille4'),(262,'2021-12-14 21:58:03','debit->credit',20,0,4,'tililtä4'),(263,'2021-12-14 21:58:03','credit->debit',-20,1,4,'tilille4'),(264,'2021-12-14 21:58:03','debit->credit',20,0,4,'tililtä4'),(265,'2021-12-14 22:00:04','credit->debit',-20,1,4,'tililledebit'),(266,'2021-12-14 22:00:04','debit->credit',20,0,4,'tililtäcredit'),(267,'2021-12-14 22:00:04','credit->debit',-20,1,4,'tililledebit'),(268,'2021-12-14 22:00:04','debit->credit',20,0,4,'tililtäcredit'),(269,'2021-12-14 22:00:06','credit->debit',-20,1,4,'tililledebit'),(270,'2021-12-14 22:00:06','debit->credit',20,0,4,'tililtäcredit'),(271,'2021-12-14 22:00:08','credit->debit',-20,1,4,'tililledebit'),(272,'2021-12-14 22:00:08','debit->credit',20,0,4,'tililtäcredit'),(273,'2021-12-14 22:00:12','credit->debit',-20,1,4,'tililledebit'),(274,'2021-12-14 22:00:12','debit->credit',20,0,4,'tililtäcredit'),(275,'2021-12-14 22:01:40','debit->credit',25,0,4,'tililtäcredit'),(276,'2021-12-14 22:01:41','debit->credit',25,0,4,'tililtäcredit'),(277,'2021-12-14 22:01:41','debit->credit',25,0,4,'tililtäcredit'),(278,'2021-12-14 22:01:42','debit->credit',25,0,4,'tililtäcredit'),(279,'2021-12-14 22:01:43','debit->credit',25,0,4,'tililtäcredit'),(280,'2021-12-14 22:01:43','debit->credit',25,0,4,'tililtäcredit'),(281,'2021-12-14 22:01:51','debit->credit',25,0,4,'tililtäcredit'),(282,'2021-12-14 22:01:51','debit->credit',25,0,4,'tililtäcredit'),(283,'2021-12-14 22:01:58','debit->credit',25,0,4,'tililtäcredit'),(284,'2021-12-14 22:01:59','debit->credit',25,0,4,'tililtäcredit'),(285,'2021-12-14 22:01:59','debit->credit',25,0,4,'tililtäcredit'),(286,'2021-12-14 22:02:05','debit->credit',25,0,4,'tililtäcredit'),(287,'2021-12-14 22:02:06','debit->credit',25,0,4,'tililtäcredit'),(288,'2021-12-14 22:03:10','debit->credit',25,0,4,'tililtäcredit'),(289,'2021-12-14 22:03:10','debit->credit',25,0,4,'tililtäcredit'),(290,'2021-12-14 22:03:10','debit->credit',25,0,4,'tililtäcredit'),(291,'2021-12-14 22:03:23','debit->credit',25,0,3,'tililtäcredit'),(292,'2021-12-14 22:03:24','debit->credit',25,0,3,'tililtäcredit'),(293,'2021-12-14 22:03:24','debit->credit',25,0,3,'tililtäcredit'),(294,'2021-12-14 22:03:25','debit->credit',25,0,3,'tililtäcredit'),(295,'2021-12-14 22:03:25','debit->credit',25,0,3,'tililtäcredit'),(296,'2021-12-14 22:03:26','debit->credit',25,0,3,'tililtäcredit'),(297,'2021-12-14 22:03:33','debit->credit',25,0,3,'tililtäcredit'),(298,'2021-12-14 22:03:33','debit->credit',25,0,3,'tililtäcredit'),(299,'2021-12-14 22:03:34','debit->credit',25,0,3,'tililtäcredit'),(300,'2021-12-14 22:30:47','credit->debit',25,0,3,'tililtä credit'),(301,'2021-12-14 22:41:41','credit->debit',25,0,3,'tililtä credit'),(302,'2021-12-14 22:41:48','credit->debit',25,0,5,'tililtä credit'),(303,'2021-12-14 22:47:55','debit->credit',10,1,3,'tililtä debit'),(304,'2021-12-14 22:47:58','debit->credit',10,1,3,'tililtä debit'),(305,'2021-12-14 22:49:58','debit->credit',10,1,3,'tililtä debit'),(306,'2021-12-14 22:49:59','debit->credit',10,1,3,'tililtä debit'),(307,'2021-12-14 22:51:06','debit->credit',10,1,3,'tililtä debit'),(308,'2021-12-14 22:51:12','debit->credit',100,1,3,'tililtä debit'),(309,'2021-12-14 22:52:06','debit->credit',99,1,3,'tililtä debit'),(310,'2021-12-14 22:54:32','debit->credit',99,1,3,'tililtä debit'),(311,'2021-12-14 22:58:38','debit->credit',99,1,3,'tililtä debit'),(312,'2021-12-14 22:58:44','debit->credit',101,1,3,'tililtä debit'),(314,'2021-12-14 23:11:09','debit->credit',5,1,3,'tililtä debit'),(315,'2021-12-14 23:11:17','debit->credit',25,1,3,'tililtä debit'),(316,'2021-12-14 23:12:20','debit->credit',5,1,3,'tililtä debit'),(317,'2021-12-14 23:13:20','debit->credit',100,1,3,'tililtä debit'),(318,'2021-12-14 23:13:26','credit->debit',100,0,3,'tililtä credit'),(319,'2021-12-14 23:13:26','credit->debit',50,0,3,'tililtä credit'),(320,'2021-12-14 23:18:52','debit->credit',5,1,3,'tililtä debit'),(321,'2021-12-14 23:23:52','Talletus',1000,0,3,'Pankkikortti#4'),(322,'2021-12-14 23:25:24','Talletus',500,0,3,'Pankkikortti#4'),(323,'2021-12-14 23:25:41','Talletus',38,0,3,'Pankkikortti#4'),(324,'2021-12-14 23:26:17','debit->credit',5000,1,3,'tililtä debit'),(325,'2021-12-14 23:28:03','debit->credit',500,1,3,'tililtä debit'),(328,'2021-12-14 23:29:33','debit->credit',5,1,3,'tililtä debit'),(329,'2021-12-14 23:29:39','debit->credit',10,1,3,'tililtä debit'),(330,'2021-12-14 23:32:43','credit->debit',5,0,3,'tililtä credit'),(331,'2021-12-14 23:32:43','credit->debit',12,0,3,'tililtä credit'),(332,'2021-12-14 23:32:55','credit->debit',12,0,3,'tililtä credit'),(333,'2021-12-14 23:33:10','debit->credit',16,1,3,'tililtä debit'),(334,'2021-12-14 23:34:41','debit->credit',15,1,3,'tililtä debit'),(335,'2021-12-14 23:34:56','debit->credit',12,1,3,'tililtä debit'),(336,'2021-12-14 23:35:01','credit->debit',20,0,3,'tililtä credit'),(337,'2021-12-14 23:35:01','credit->debit',50,0,3,'tililtä credit'),(338,'2021-12-14 23:36:24','debit->credit',5,1,3,'tililtä debit'),(339,'2021-12-14 23:36:38','debit->credit',12,1,3,'tililtä debit'),(340,'2021-12-14 23:36:41','credit->debit',12,0,3,'tililtä credit'),(341,'2021-12-14 23:36:41','credit->debit',20,0,3,'tililtä credit'),(342,'2021-12-14 23:37:42','debit->credit',20,1,3,'tililtä debit'),(343,'2021-12-14 23:39:17','debit->credit',5,1,3,'tililtä debit'),(344,'2021-12-14 23:40:11','debit->credit',6,1,3,'tililtä debit'),(345,'2021-12-14 23:40:56','debit->credit',7,1,3,'tililtä debit'),(346,'2021-12-14 23:40:59','debit->credit',7,1,3,'tililtä debit'),(348,'2021-12-16 15:18:53','Nosto tililtä',-20,0,3,'Pankkikortti#4'),(349,'2021-12-16 15:20:25','tilisiirto',-10,0,3,'tilille5'),(350,'2021-12-16 15:20:25','tilisiirto',10,0,5,'tililtä3'),(351,'2021-12-16 15:20:29','tilisiirto',-50,0,3,'tilille5'),(352,'2021-12-16 15:20:29','tilisiirto',50,0,5,'tililtä3'),(353,'2021-12-16 15:20:37','tilisiirto',-31,0,3,'tilille5'),(354,'2021-12-16 15:20:37','tilisiirto',31,0,5,'tililtä3'),(355,'2021-12-16 15:21:11','tilisiirto',-100,1,3,'tilille5'),(356,'2021-12-16 15:21:11','tilisiirto',100,1,5,'tililtä3'),(357,'2021-12-16 15:25:21','Talletus',10,0,3,'Pankkikortti#3'),(358,'2021-12-16 15:35:00','tilisiirto',-10,0,3,'tilille5'),(359,'2021-12-16 15:35:00','tilisiirto',10,0,5,'tililtä3'),(360,'2021-12-16 15:35:03','tilisiirto',-10,0,3,'tilille5'),(361,'2021-12-16 15:35:03','tilisiirto',10,0,5,'tililtä3'),(362,'2021-12-16 15:35:06','tilisiirto',-10,0,3,'tilille5'),(363,'2021-12-16 15:35:06','tilisiirto',10,1,5,'tililtä3'),(364,'2021-12-16 15:35:10','tilisiirto',-10,0,3,'tilille5'),(365,'2021-12-16 15:35:10','tilisiirto',10,1,5,'tililtä3'),(366,'2021-12-16 15:36:50','debit->credit',5,1,3,'tililtä debit'),(367,'2021-12-16 15:36:59','debit->credit',10,1,3,'tililtä debit'),(368,'2021-12-16 15:37:38','debit->credit',10,1,3,'tililtä debit'),(370,'2021-12-16 15:41:07','debit->credit',15,1,3,'tililtä debit'),(373,'2021-12-16 15:48:20','debit->credit',5,1,3,'tililtä debit'),(374,'2021-12-16 15:48:27','debit->credit',15,1,3,'tililtä debit'),(375,'2021-12-16 15:48:27','debit->credit',0,1,3,'tililtä debit'),(376,'2021-12-16 15:48:28','debit->credit',0,1,3,'tililtä debit'),(377,'2021-12-16 15:48:28','debit->credit',0,1,3,'tililtä debit'),(378,'2021-12-16 15:49:28','debit->credit',5,1,3,'tililtä debit'),(380,'2021-12-16 15:53:08','debit->credit',25,1,3,'tililtä debit'),(381,'2021-12-16 15:54:26','debit->credit',30,1,3,'tililtä debit'),(382,'2021-12-16 15:55:19','credit->debit',10,0,3,'tililtä credit'),(383,'2021-12-16 15:58:11','credit->debit',5,0,3,'tililtä credit');
/*!40000 ALTER TABLE `tapahtumat` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Dumping routines for database 'pankkisimulaattori'
--
/*!50003 DROP PROCEDURE IF EXISTS `credit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_tilisiirto`(
IN tilinumero1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT saldoUlos DOUBLE)
BEGIN
  DECLARE test2, creditraja INT DEFAULT 0;
  START TRANSACTION;
    SELECT luottoraja INTO creditraja FROM pankkitili WHERE tilinumero = tilinumero1;
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 1 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '1', tilinumero1, concat("tilille",tilinumero2));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '1', tilinumero2, concat("tililtä",tilinumero1));
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
	  IF (creditKayttaja = 1 AND creditVastaanottaja = 0 AND creditraja > summa) THEN UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '1', tilinumero1, concat("tilille",tilinumero2));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '0', tilinumero2, concat("tililtä",tilinumero1));
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT luottoraja + creditsaldo INTO saldoUlos FROM pankkitili WHERE tilinumero = tilinumero1;
	SELECT saldoUlos;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `credit_to_debit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_to_debit`(
IN tilinumero1 INT, 
IN summa DOUBLE,
OUT saldoUlos INT)
BEGIN
DECLARE creditArvo, luotto DOUBLE;
START TRANSACTION;
SELECT creditsaldo INTO creditArvo FROM pankkitili WHERE tilinumero = tilinumero1;
SELECT luottoraja INTO luotto FROM pankkitili WHERE tilinumero = tilinumero1;
IF (creditArvo + luotto >= summa) THEN
COMMIT; 
	UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=tilinumero1;
	UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero1;
	INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), "credit->debit", summa, '0', tilinumero1, "tililtä credit");
    SET saldoUlos = -1;
ELSE SET saldoUlos = -2;
ROLLBACK;
END IF;
SELECT saldoUlos;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_tilisiirto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_tilisiirto`(
IN tilinumero1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT saldoUlos DOUBLE)
BEGIN
  DECLARE test2, korttinumero2, luottoRaja INT DEFAULT 0;
  START TRANSACTION;
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 1) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '0', tilinumero1, concat("tilille",tilinumero2));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '1', tilinumero2, concat("tililtä",tilinumero1));
			ELSE
			  ROLLBACK;
		  END IF;
	  END IF;
  
	  IF (creditKayttaja = 0 AND creditVastaanottaja = 0) THEN UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>=summa;
	  SET test2=ROW_COUNT();
		  IF (test2 >0) THEN   
			  COMMIT;    
				UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinumero2;
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '0', tilinumero1, concat("tilille",tilinumero2));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '0', tilinumero2, concat("tililtä",tilinumero1));
		  ELSE ROLLBACK;
		  END IF;
	  END IF;
	SELECT saldo INTO saldoUlos FROM pankkitili WHERE tilinumero = tilinumero1;
    SELECT saldoUlos;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `debit_to_credit` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_to_credit`(
IN tilinumero1 INT, 
IN summa DOUBLE,
OUT saldoUlos TINYINT)
BEGIN
DECLARE test2 int DEFAULT 0;
START TRANSACTION;
    UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinumero1 AND saldo>summa;
    UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=tilinumero1;
	INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), "debit->credit", summa, '1', tilinumero1, "tililtä debit");
	SET test2=ROW_COUNT();
    IF (test2 > 0) THEN SET saldoUlos = -1;
    ELSE SET saldoUlos = -2;
    END IF;
    SELECT saldoUlos;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `otto` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `otto`(IN id1 INT, IN summa DOUBLE, IN luotto TINYINT)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  DECLARE m_s varchar(20) DEFAULT 'Pankkikortti#';
   DECLARE tilinro int DEFAULT 0;
  START TRANSACTION;
  SELECT pankkitili.tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=id1;
  IF luotto = 1 THEN
	UPDATE pankkitili SET credit=credit-summa WHERE tilinumero=tilinro;
ELSE
	UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=tilinro;
END IF;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT; 
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja) VALUES(NULL, NOW(), 'Nosto tililtä', -summa, 0, tilinro, CONCAT(m_s,id1));
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `pin_Katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `pin_Katsaus`(
IN id1 INT,
IN pin TINYINT,
OUT laskuri INT
)
BEGIN
IF (pin = 1) THEN UPDATE pankkikortti SET pankkikortti.pinVaarin=0 WHERE korttinumero=id1;
ELSE IF (pin = 0) THEN
    UPDATE pankkikortti SET pankkikortti.pinVaarin=pankkikortti.pinVaarin+1 WHERE korttinumero=id1;
END IF;
END IF;
IF (laskuri > 2) THEN DELETE FROM pankkikortti WHERE korttinumero = id1; 
END IF;
SELECT pinVaarin INTO laskuri from pankkikortti WHERE korttinumero = id1;
SELECT laskuri;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `saldo_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `saldo_katsaus`(IN id1 INT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO credit;
SELECT pankkikortti.tilinumero FROM pankkikortti WHERE pankkikortti.korttinumero = id1 INTO id2;
IF (credit = 1) THEN SELECT pankkitili.saldo, pankkitili.creditsaldo, luottoraja, nimi FROM pankkitili JOIN asiakas_pankkitili ON asiakas_pankkitili.tilinumero=pankkitili.tilinumero JOIN asiakas ON asiakas.idasiakas=asiakas_pankkitili.idasiakas WHERE pankkitili.tilinumero = id2;
ELSE SELECT pankkitili.saldo, nimi FROM pankkitili JOIN asiakas_pankkitili ON asiakas_pankkitili.tilinumero=pankkitili.tilinumero JOIN asiakas ON asiakas.idasiakas=asiakas_pankkitili.idasiakas WHERE pankkitili.tilinumero = id2;
END IF;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `talletus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `talletus`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  DECLARE tilinro int DEFAULT 0;
  DECLARE m_s varchar(20) DEFAULT 'Pankkikortti#';
  SELECT pankkitili.tilinumero INTO tilinro FROM pankkitili JOIN pankkikortti ON pankkitili.tilinumero=pankkikortti.tilinumero WHERE korttinumero=id1;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=tilinro;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja) VALUES(NULL, NOW(), 'Talletus', summa, 0, tilinro, CONCAT(m_s,id1));
    ELSE
      ROLLBACK;
  END IF;
  END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tilitapahtuma_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tilitapahtuma_katsaus`(
IN tilinumero1 INT,
IN luotto TINYINT,
IN alkaenRivilta INT
)
BEGIN
	SELECT * FROM tapahtumat WHERE tilinumero=tilinumero1 ORDER BY aikaleima DESC LIMIT alkaenRivilta, 10;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `tili_katsaus` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `tili_katsaus`(
IN id1 INT,
OUT omistaja VARCHAR(20),
OUT creditSaldo FLOAT,
OUT debitSaldo FLOAT)
BEGIN
DECLARE credit tinyint;
DECLARE id2 int;
SELECT pankkikortti.credit INTO credit FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT pankkikortti.tilinumero INTO id2 FROM pankkikortti WHERE pankkikortti.korttinumero = id1;
SELECT nimi INTO omistaja FROM asiakas JOIN asiakas_pankkitili ON asiakas_pankkitili.idasiakas = asiakas.idasiakas JOIN pankkitili ON pankkitili.tilinumero = asiakas_pankkitili.tilinumero WHERE pankkitili.tilinumero = id2;
SELECT pankkitili.saldo INTO debitSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2; 
SELECT pankkitili.creditsaldo INTO creditSaldo FROM pankkitili WHERE pankkitili.tilinumero = id2;
IF (credit = 1) THEN SELECT omistaja, debitSaldo, creditSaldo;
ELSE SELECT omistaja, debitSaldo;
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

-- Dump completed on 2021-12-16 15:59:49
>>>>>>> Stashed changes:pankkiautomaatti_tietokantadump_16122021.sql
