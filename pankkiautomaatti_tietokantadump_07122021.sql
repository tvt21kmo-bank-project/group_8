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
INSERT INTO `asiakas` VALUES (1,'Sauli Partanen','Uusikatu','89455497'),(2,'Samuli','Salmi','708345543'),(3,'Tero','Vähäsarja','703454537');
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
INSERT INTO `asiakas_pankkitili` VALUES (1,1);
/*!40000 ALTER TABLE `asiakas_pankkitili` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkikortti`
--

DROP TABLE IF EXISTS `pankkikortti`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkikortti` (
  `korttinumero` int NOT NULL,
  `pin` varchar(60) DEFAULT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  `pinVaarin` int DEFAULT '0',
  PRIMARY KEY (`korttinumero`,`tilinumero`),
  KEY `fk_pankkikortti_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_pankkikortti_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkikortti`
--

LOCK TABLES `pankkikortti` WRITE;
/*!40000 ALTER TABLE `pankkikortti` DISABLE KEYS */;
/*!40000 ALTER TABLE `pankkikortti` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `pankkitili`
--

DROP TABLE IF EXISTS `pankkitili`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `pankkitili` (
  `tilinumero` int NOT NULL,
  `saldo` float NOT NULL,
  `creditsaldo` float DEFAULT NULL,
  PRIMARY KEY (`tilinumero`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `pankkitili`
--

LOCK TABLES `pankkitili` WRITE;
/*!40000 ALTER TABLE `pankkitili` DISABLE KEYS */;
INSERT INTO `pankkitili` VALUES (1,500,220),(2,575,575),(3,1000,0);
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
  `summa` float NOT NULL,
  `credit` tinyint NOT NULL,
  `tilinumero` int NOT NULL,
  PRIMARY KEY (`idtapahtumat`),
  KEY `fk_tapahtumat_pankkitili1_idx` (`tilinumero`),
  CONSTRAINT `fk_tapahtumat_pankkitili1` FOREIGN KEY (`tilinumero`) REFERENCES `pankkitili` (`tilinumero`)
) ENGINE=InnoDB AUTO_INCREMENT=58 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (1,'2021-11-21 01:39:34','otto',5,0,1),(2,'2021-11-21 01:39:34','talletus',5,0,2),(3,'2021-11-21 01:52:19','otto',10,0,2),(4,'2021-11-21 01:52:19','talletus',10,0,1),(5,'2021-11-21 01:55:43','otto',100,1,1),(6,'2021-11-21 01:55:43','talletus',100,1,2),(7,'2021-11-21 13:15:39','otto',10,0,2),(8,'2021-11-21 13:22:49','talletus',100,0,1),(9,'2021-11-21 13:22:57','talletus',100,0,2),(10,'2021-11-21 13:34:43','siirto',80,0,1),(11,'2021-11-21 13:34:43','talletus',80,1,1),(12,'2021-11-21 13:38:11','talletus',100,0,1),(13,'2021-11-21 13:38:34','siirto',20,0,1),(14,'2021-11-21 13:38:34','talletus',20,1,1),(15,'2021-11-21 13:38:51','talletus',5,0,2),(16,'2021-11-21 13:38:51','siirto',5,1,2),(17,'2021-11-21 14:01:52','otto',110,0,2),(18,'2021-11-21 14:02:50','otto',10,0,1),(19,'2021-11-21 14:02:50','talletus',10,0,2),(20,'2021-11-21 14:04:27','otto',50,1,2),(21,'2021-11-21 14:04:27','talletus',50,1,1),(22,'2021-11-21 14:09:10','otto',10,0,2),(23,'2021-11-21 14:23:43','otto',10,0,1),(24,'2021-11-21 14:26:47','otto',10,0,1),(25,'2021-11-21 14:27:52','otto',10,0,1),(26,'2021-11-21 14:30:51','talletus',100,0,2),(27,'2021-11-21 14:32:06','talletus',100,0,1),(28,'2021-11-21 14:37:37','siirto',160,0,1),(29,'2021-11-21 14:37:37','talletus',160,1,1),(30,'2021-11-21 14:38:26','talletus',50,0,2),(31,'2021-11-21 14:38:26','siirto',50,1,2),(32,'2021-11-21 14:38:47','talletus',100,0,1),(33,'2021-11-21 14:38:47','siirto',100,1,1),(34,'2021-12-01 14:19:30','otto',10,0,1),(35,'2021-12-01 14:19:30','talletus',10,0,2),(36,'2021-12-02 14:32:00','talletus',100,0,3),(37,'2021-12-02 14:34:54','siirto',50,0,2),(38,'2021-12-02 14:34:54','talletus',50,1,2),(39,'2021-12-02 14:35:05','siirto',50,0,2),(40,'2021-12-02 14:35:05','talletus',50,1,2),(41,'2021-12-02 14:35:38','talletus',100,0,2),(42,'2021-12-02 14:35:38','siirto',100,1,2),(43,'2021-12-02 14:35:54','siirto',150,0,2),(44,'2021-12-02 14:35:54','talletus',150,1,2),(45,'2021-12-04 16:07:36','talletus',1000,0,3),(46,'2021-12-04 16:08:03','otto',500,0,3),(47,'2021-12-04 16:08:03','talletus',500,0,1),(48,'2021-12-04 16:08:30','otto',50,0,3),(49,'2021-12-04 16:08:37','otto',50,0,3),(50,'2021-12-04 16:08:46','talletus',550,0,3),(51,'2021-12-04 16:09:17','siirto',90,0,1),(52,'2021-12-04 16:09:17','talletus',90,1,1),(53,'2021-12-04 16:09:40','talletus',940,0,2),(54,'2021-12-04 16:09:53','siirto',500,0,2),(55,'2021-12-04 16:09:53','talletus',500,1,2),(56,'2021-12-04 16:10:36','talletus',75,0,2),(57,'2021-12-04 16:10:36','siirto',75,1,2);
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `credit_tilisiirto`(IN id1 INT, IN id2 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET creditsaldo=creditsaldo-summa WHERE tilinumero=id1;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET creditsaldo=creditsaldo+summa WHERE tilinumero=id2;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'otto', summa, id1, '1');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id2, '1');
    ELSE
      ROLLBACK;
  END IF;
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `debit_tilisiirto`(IN id1 INT, IN id2 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1,test2 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=id1 AND saldo>=summa;
  SET test1=ROW_COUNT();
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=id2;
  SET test2=ROW_COUNT();
    IF (test1 > 0 AND test2 >0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'otto', summa, id1, '0');
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id2, '0');
    ELSE
      ROLLBACK;
  END IF;
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `otto`(IN id1 INT, IN summa DOUBLE)
BEGIN
  DECLARE test1 INT DEFAULT 0;
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo-summa WHERE tilinumero=id1 AND saldo>=summa;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'otto', summa, id1, '0');
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
IN id2 TINYINT,
OUT laskuri INT
)
BEGIN
IF (id2 = 1) THEN UPDATE pankkikortti SET pankkikortti.pinVaarin=0 WHERE korttinumero=id1;
ELSE IF (id2 = 0) THEN
    UPDATE pankkikortti SET pankkikortti.pinVaarin=pankkikortti.pinVaarin+1 WHERE korttinumero=id1;
    SELECT pinVaarin INTO laskuri from pankkikortti WHERE korttinumero = id1;
END IF;
END IF;
IF (laskuri > 2) THEN DELETE FROM pankkikortti WHERE korttinumero = id1; 
END IF;
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
IF (credit = 1) THEN SELECT pankkitili.saldo, pankkitili.creditsaldo FROM pankkitili WHERE pankkitili.tilinumero = id2;
ELSE SELECT pankkitili.saldo FROM pankkitili WHERE pankkitili.tilinumero = id2; 
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
  START TRANSACTION;
  UPDATE pankkitili SET saldo=saldo+summa WHERE tilinumero=id1;
  SET test1=ROW_COUNT();
    IF (test1 > 0) THEN   
      COMMIT;    
      INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, tilinumero, credit) VALUES(NULL, NOW(), 'talletus', summa, id1, '0');
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
CREATE DEFINER=`root`@`localhost` PROCEDURE `tilitapahtuma_katsaus`(IN id1 INT)
BEGIN
	DECLARE id2 INT;
    SELECT tilinumero INTO id2 FROM pankkikortti WHERE korttinumero = id1;
	SELECT * FROM tapahtumat WHERE tilinumero=id2 ORDER BY aikaleima LIMIT 10, 10;
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

-- Dump completed on 2021-12-07 15:53:10
