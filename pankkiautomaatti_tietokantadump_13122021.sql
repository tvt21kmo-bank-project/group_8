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
INSERT INTO `pankkitili` VALUES (3,4030,1189,14811),(4,56,NULL,NULL),(5,302.85,-298,2000);
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
) ENGINE=InnoDB AUTO_INCREMENT=173 DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `tapahtumat`
--

LOCK TABLES `tapahtumat` WRITE;
/*!40000 ALTER TABLE `tapahtumat` DISABLE KEYS */;
INSERT INTO `tapahtumat` VALUES (58,'2021-12-12 14:05:13','Talletus',1,0,5,'Pankkikortti#7'),(59,'2021-12-12 17:24:10','Talletus',200,0,5,'Pankkikortti#7'),(60,'2021-12-12 17:25:00','Nosto tililtä',-40,0,5,'Pankkikortti#7'),(61,'2021-12-12 20:07:56','Nosto tililtä',-500,0,3,'Pankkikortti#4'),(62,'2021-12-12 20:08:16','Talletus',125,0,3,'Pankkikortti#4'),(63,'2021-12-12 20:09:10','Nosto tililtä',-20,0,4,'Pankkikortti#5'),(64,'2021-12-13 14:24:19','tilisiirto',0,-6,3,'4'),(65,'2021-12-13 14:25:19','tilisiirto',0,-6,3,'4'),(66,'2021-12-13 14:25:19','tilisiirto',1,6,5,'7'),(67,'2021-12-13 14:25:58','tilisiirto',0,-5,3,'4'),(68,'2021-12-13 14:25:58','tilisiirto',1,5,5,'7'),(69,'2021-12-13 14:30:13','tilisiirto',0,-9,3,'4'),(70,'2021-12-13 14:30:13','tilisiirto',1,9,5,'7'),(71,'2021-12-13 21:56:46','tilisiirto',0,-9,4,'tilille5'),(72,'2021-12-13 21:56:46','tilisiirto',1,9,5,'tililtä4'),(73,'2021-12-13 21:56:54','tilisiirto',0,-1,4,'tilille5'),(74,'2021-12-13 21:56:54','tilisiirto',1,1,5,'tililtä4'),(75,'2021-12-13 21:56:58','tilisiirto',0,-10,4,'tilille5'),(76,'2021-12-13 21:56:58','tilisiirto',1,10,5,'tililtä4'),(77,'2021-12-13 22:06:06','tilisiirto',0,-10,4,'tilille3'),(78,'2021-12-13 22:06:06','tilisiirto',1,10,3,'tililtä4'),(79,'2021-12-13 22:06:19','tilisiirto',0,-10,4,'tilille3'),(80,'2021-12-13 22:06:19','tilisiirto',1,10,3,'tililtä4'),(81,'2021-12-13 22:06:20','tilisiirto',0,-10,4,'tilille3'),(82,'2021-12-13 22:06:20','tilisiirto',1,10,3,'tililtä4'),(83,'2021-12-13 22:13:45','tilisiirto',0,-2,3,'tilille3'),(84,'2021-12-13 22:13:45','tilisiirto',0,2,5,'tililtä5'),(85,'2021-12-13 22:22:52','tilisiirto',0,-10,4,'tilille3'),(86,'2021-12-13 22:22:52','tilisiirto',1,10,3,'tililtä4'),(87,'2021-12-13 22:23:24','tilisiirto',0,-10,4,'tilille3'),(88,'2021-12-13 22:23:24','tilisiirto',1,10,3,'tililtä4'),(89,'2021-12-13 22:25:36','tilisiirto',0,-10,4,'tilille3'),(90,'2021-12-13 22:25:36','tilisiirto',1,10,3,'tililtä4'),(91,'2021-12-13 22:29:21','tilisiirto',0,0,4,'tilille3'),(92,'2021-12-13 22:29:21','tilisiirto',1,0,3,'tililtä4'),(93,'2021-12-13 22:29:22','tilisiirto',0,0,4,'tilille3'),(94,'2021-12-13 22:29:22','tilisiirto',1,0,3,'tililtä4'),(95,'2021-12-13 22:29:23','tilisiirto',0,0,4,'tilille3'),(96,'2021-12-13 22:29:23','tilisiirto',1,0,3,'tililtä4'),(97,'2021-12-13 22:30:50','tilisiirto',0,-5,3,'tilille3'),(98,'2021-12-13 22:30:50','tilisiirto',0,5,5,'tililtä5'),(99,'2021-12-13 22:31:25','tilisiirto',0,-2,3,'tilille3'),(100,'2021-12-13 22:31:25','tilisiirto',0,2,5,'tililtä5'),(101,'2021-12-13 23:02:30','tilisiirto',0,-2,3,'tilille3'),(102,'2021-12-13 23:02:30','tilisiirto',0,2,5,'tililtä5'),(103,'2021-12-13 23:03:55','tilisiirto',0,-36,3,'tilille3'),(104,'2021-12-13 23:03:55','tilisiirto',0,36,4,'tililtä4'),(105,'2021-12-13 23:04:49','tilisiirto',0,-2,3,'tilille3'),(106,'2021-12-13 23:04:49','tilisiirto',0,2,5,'tililtä5'),(107,'2021-12-13 23:07:54','tilisiirto',0,-5,3,'tilille3'),(108,'2021-12-13 23:07:54','tilisiirto',0,5,5,'tililtä5'),(109,'2021-12-13 23:14:14','tilisiirto',0,-5,3,'tilille3'),(110,'2021-12-13 23:14:14','tilisiirto',0,5,5,'tililtä5'),(111,'2021-12-13 23:14:49','tilisiirto',0,-5,3,'tilille3'),(112,'2021-12-13 23:14:49','tilisiirto',0,5,5,'tililtä5'),(113,'2021-12-13 23:16:20','tilisiirto',0,-12,3,'tilille3'),(114,'2021-12-13 23:16:20','tilisiirto',0,12,5,'tililtä5'),(115,'2021-12-13 23:16:49','tilisiirto',0,-10,3,'tilille3'),(116,'2021-12-13 23:16:49','tilisiirto',0,10,5,'tililtä5'),(117,'2021-12-13 23:16:56','tilisiirto',0,-10,3,'tilille3'),(118,'2021-12-13 23:16:56','tilisiirto',0,10,5,'tililtä5'),(119,'2021-12-13 23:16:59','tilisiirto',0,-10,3,'tilille3'),(120,'2021-12-13 23:16:59','tilisiirto',0,10,5,'tililtä5'),(121,'2021-12-13 23:20:50','tilisiirto',-2,0,3,'tilille3'),(122,'2021-12-13 23:20:50','tilisiirto',2,0,5,'tililtä5'),(123,'2021-12-13 23:20:52','tilisiirto',-2,0,3,'tilille3'),(124,'2021-12-13 23:20:52','tilisiirto',2,0,5,'tililtä5'),(125,'2021-12-13 23:20:54','tilisiirto',-2,0,3,'tilille3'),(126,'2021-12-13 23:20:54','tilisiirto',2,0,5,'tililtä5'),(127,'2021-12-13 23:20:56','tilisiirto',-5,0,3,'tilille3'),(128,'2021-12-13 23:20:56','tilisiirto',5,0,5,'tililtä5'),(129,'2021-12-13 23:24:36','tilisiirto',-10,1,3,'tilille5'),(130,'2021-12-13 23:24:36','tilisiirto',10,1,5,'tililtä3'),(131,'2021-12-13 23:24:46','tilisiirto',-10,1,3,'tilille5'),(132,'2021-12-13 23:24:46','tilisiirto',10,1,5,'tililtä3'),(133,'2021-12-13 23:24:47','tilisiirto',-10,1,3,'tilille5'),(134,'2021-12-13 23:24:47','tilisiirto',10,1,5,'tililtä3'),(135,'2021-12-13 23:24:48','tilisiirto',-10,1,3,'tilille5'),(136,'2021-12-13 23:24:48','tilisiirto',10,1,5,'tililtä3'),(137,'2021-12-13 23:27:37','tilisiirto',-10,1,3,'tilille5'),(138,'2021-12-13 23:27:37','tilisiirto',10,1,5,'tililtä3'),(139,'2021-12-13 23:27:40','tilisiirto',-10,1,3,'tilille5'),(140,'2021-12-13 23:27:40','tilisiirto',10,1,5,'tililtä3'),(141,'2021-12-13 23:27:41','tilisiirto',-10,1,3,'tilille5'),(142,'2021-12-13 23:27:41','tilisiirto',10,1,5,'tililtä3'),(143,'2021-12-13 23:27:42','tilisiirto',-10,1,3,'tilille5'),(144,'2021-12-13 23:27:42','tilisiirto',10,1,5,'tililtä3'),(145,'2021-12-13 23:29:08','tilisiirto',-29,1,3,'tilille5'),(146,'2021-12-13 23:29:08','tilisiirto',29,1,5,'tililtä3'),(147,'2021-12-13 23:33:33','tilisiirto',-10,1,3,'tilille5'),(148,'2021-12-13 23:33:33','tilisiirto',10,1,5,'tililtä3'),(149,'2021-12-13 23:34:52','tilisiirto',-5,1,3,'tilille5'),(150,'2021-12-13 23:34:52','tilisiirto',5,1,5,'tililtä3'),(151,'2021-12-13 23:34:58','tilisiirto',-5,1,3,'tilille5'),(152,'2021-12-13 23:34:58','tilisiirto',5,1,5,'tililtä3'),(153,'2021-12-13 23:35:44','tilisiirto',-15,1,3,'tilille5'),(154,'2021-12-13 23:35:44','tilisiirto',15,1,5,'tililtä3'),(155,'2021-12-13 23:35:50','tilisiirto',-20,1,3,'tilille5'),(156,'2021-12-13 23:35:50','tilisiirto',20,1,5,'tililtä3'),(157,'2021-12-13 23:35:54','tilisiirto',-2,1,3,'tilille5'),(158,'2021-12-13 23:35:54','tilisiirto',2,1,5,'tililtä3'),(159,'2021-12-13 23:35:59','tilisiirto',-8,1,3,'tilille5'),(160,'2021-12-13 23:35:59','tilisiirto',8,1,5,'tililtä3'),(161,'2021-12-13 23:36:01','tilisiirto',-2,1,3,'tilille5'),(162,'2021-12-13 23:36:01','tilisiirto',2,1,5,'tililtä3'),(163,'2021-12-13 23:37:49','tilisiirto',-5,1,3,'tilille5'),(164,'2021-12-13 23:37:49','tilisiirto',5,1,5,'tililtä3'),(165,'2021-12-13 23:37:58','tilisiirto',-8,1,3,'tilille5'),(166,'2021-12-13 23:37:58','tilisiirto',8,1,5,'tililtä3'),(167,'2021-12-13 23:41:23','tilisiirto',-20,1,3,'tilille5'),(168,'2021-12-13 23:41:23','tilisiirto',20,1,5,'tililtä3'),(169,'2021-12-13 23:41:27','tilisiirto',-2,1,3,'tilille5'),(170,'2021-12-13 23:41:27','tilisiirto',2,1,5,'tililtä3'),(171,'2021-12-13 23:41:30','tilisiirto',-100,1,3,'tilille5'),(172,'2021-12-13 23:41:30','tilisiirto',100,1,5,'tililtä3');
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
OUT saldoUlos FLOAT)
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
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '1', tilinumero1, concat("tilille",tilinumero1));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '0', tilinumero2, concat("tililtä",tilinumero2));
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
IN tilinumero1 INT,
IN tilinumero2 INT,
IN creditKayttaja TINYINT,
IN creditVastaanottaja TINYINT,
IN summa DOUBLE,
OUT saldoUlos FLOAT)
BEGIN
  DECLARE test2, korttinumero2 INT DEFAULT 0;
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
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', -summa, '0', tilinumero1, concat("tilille",tilinumero1));
			  INSERT INTO tapahtumat(idtapahtumat, aikaleima, tapahtuma, summa, credit, tilinumero, maksaja_saaja ) VALUES(NULL, NOW(), 'tilisiirto', summa, '0', tilinumero2, concat("tililtä",tilinumero2));
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

-- Dump completed on 2021-12-13 23:48:30
