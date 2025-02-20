<?php
  require_once('Petshop.php');
  if (session_status() == PHP_SESSION_NONE) { session_start(); }

  header('Content-Type: application/json');
  $data = json_decode(file_get_contents('php://input'), true);
  $response = ["message" => "Command not found!", "refresh" => false, "search" => null];
  if (!isset($_SESSION['newId'])) $_SESSION['newId'] = 1;
  $newId = &$_SESSION['newId'];
  $list = &$_SESSION['list'];
  $command = $data['command'];

  $parts = explode(' ', $command);
  $cmd = strtoupper($parts[0]);
  
  switch ($cmd) {
    case 'ADD':
      $addParts = explode('"', $command);
      $addNama = trim($addParts[1]);
      $addKategori = trim($addParts[3]);
      $addHarga = intval(trim($addParts[4]));
      $addFoto = trim($addParts[5]);
      $list[] = new Petshop($newId, $addNama, $addKategori, $addHarga, $addFoto);
      $newId++;
      $response["message"] = 'A new data has been added.';
      $response["refresh"] = true;
      break;
      
    case 'DELETE':
      $deleteId = intval(trim($parts[1]));
      foreach ($list as $key => $item) {
        if ($item->getID() === $deleteId) { unset($list[$key]); break; }
      }
      $response["message"] = "Data with ID $deleteId has been deleted.";
      $response["refresh"] = true;
      break;
      
    case 'UPDATE':
      $updateParts = explode('"', $command);
      $updateId = intval(trim(explode(' ', $updateParts[0])[1]));
      $updateNama = trim($updateParts[1]);
      $updateKategori = trim($updateParts[3]);
      $updateHarga = intval(trim($updateParts[4]));
      $updateFoto = trim($updateParts[5]);
      $found = false;
      foreach ($list as &$item) {
        if ($item->getID() === $updateId) {
          $item->setNama($updateNama);
          $item->setKategori($updateKategori);
          $item->setHarga($updateHarga);
          $item->setFoto($updateFoto);
          $response["message"] = "Data with ID $updateId has been updated.";
          $response["refresh"] = true;
          $found = true;
          break;
        }
      } if (!$found) $response["message"] = "Data with ID $updateId not found.";
      break;
      
    case 'SEARCH':
      $addParts = explode('"', $command);
      $searchNama = trim($addParts[1]);
      $found = false;
      foreach ($list as $item) {
        if (strpos($item->getNama(), $searchNama) !== false) {
          $found = true;
          $response["search"] = $item->getID();
          $response["message"] = "data Found!<br>";
          $response["refresh"] = true;
        }
      } if (!$found) $response["message"] = "Data with name '{$searchNama}' not found.";
      break;
    
    case 'PETSHOP':
      $response["message"] = 'Command available:<br>';
      $response["message"] .= '1. ADD "nama" "kategori" harga "foto"<br>';
      $response["message"] .= '2. DELETE ID<br>';
      $response["message"] .= '3. UPDATE ID "nama" "kategori" harga "foto"<br>';
      $response["message"] .= '4. SEARCH "nama"<br>';
      break;
      
    default:
      $response["message"] = 'Command not found!';
  }

  $_SESSION['list'] = $list;
  echo json_encode($response);
?>
