<?php
  require_once('Petshop.php');
  if (session_status() == PHP_SESSION_NONE) { session_start(); }
  
  // Initialize session list
  if (!isset($_SESSION['list'])) {
      $_SESSION['list'] = [];
  }
  $images = glob('images/*.*', GLOB_BRACE);
  $list = $_SESSION['list'];
?>

  <!DOCTYPE html>
  <html lang="en">
    <head>
      <meta charset="UTF-8">
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
      <link rel="icon" type="image/png" href="_favicon.jpg">
      <title>Daneswara's Petshop</title>
      <script src="https://unpkg.com/@tailwindcss/browser@4"></script>
    </head>
    <body class="font-sans">
      <nav class="flex justify-between bg-gray-800 text-white px-8 py-auto h-[10vh] flex items-center shadow-lg z-10">
        <h1 class="font-bold text-lg">Daneswara's Petshop</h1>
        <button onclick="toggleSidebar()" class="focus:outline-none">
          <svg class="w-6 h-6" fill="none" stroke="currentColor" viewBox="0 0 24 24" xmlns="http://www.w3.org/2000/svg">
            <path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M4 6h16M4 12h16m-7 6h7"></path>
          </svg>
        </button>
      </nav>
      <aside class="fixed right-0 p-8 w-[35%] h-[90vh] bg-gray-700 text-white transition-all duration-300 transform translate-x-[100%] z-9">
        <div class="grid grid-cols-4 gap-4">
          <?php foreach ($images as $item) { ?>
          <div class="flex flex-col items-center">
            <img src="<?php echo $item; ?>" class="w-full h-[5.25rem] object-cover rounded-lg mb-1 ratio-1x1">
            <h3 class="text-sm text-semibold"><?php echo basename($item); ?></h3>
          </div>
          <?php } ?>
        </div>
      </aside>
      <main class="w-full flex h-[80vh] justify-between container my-[5vh] px-8 gap-16">
        <section class="w-2/3 h-full overflow-y-auto shadow-lg rounded-lg outline-none"
          style="scrollbar-width: none;" id="table-container"
        >
        <?php include('list.php'); ?>
        </section>
        <section class="w-1/3">
          <div class="flex flex-col justify-between h-full bg-gray-900 text-white p-4 rounded-lg">
            <div>
              <h2 class="font-bold mb-4">Daneswara's Petshop CLI</h2>
              <div id="cli"
                class="h-[62.04vh] overflow-y-auto bg-black p-2 font-mono text-sm rounded-lg"
                style="scrollbar-width: none;"
              >
                <p>===========================================</p>
                <p>|| &nbsp; &nbsp; &nbsp;Welcome to Petshop Program! &nbsp; &nbsp; &nbsp;||</p>
                <p>===========================================</p>
              </div>
            </div>
            <input type="text" id="cli-input" class="w-full mt-4 p-2 bg-gray-800 text-white border border-gray-700 rounded-lg outline-none" placeholder="Enter command...">
          </div>

          <script>
            const cli = document.getElementById('cli');
            const cliInput = document.getElementById('cli-input');

            cliInput.addEventListener('keydown', function(event) {
              if (event.key === 'Enter') {
                const command = cliInput.value.trim();
                if (command) {
                  appendToCLI(`<br>Petshop> ${command}`);
                  cliInput.value = '';

                  fetch('cli_handler.php', {
                    method: 'POST',
                    headers: { 'Content-Type': 'application/json' },
                    body: JSON.stringify({ command })
                  })
                  .then(response => response.json())
                  .then(data => {
                    appendToCLI(data.message);
                    console.log(data);
                    if (data.refresh) refreshTable(data.search);
                  });
                }
              }
            });

            // Append CLI output
            function appendToCLI(message) {
              const output = document.createElement('p');
              output.innerHTML = message;
              cli.appendChild(output);
              cli.scrollTop = cli.scrollHeight;
            }

            // Refresh the table dynamically
            function refreshTable(search) {
              console.log(search);
              fetch(search ? 'list.php?search=' + search : 'list.php')
              .then(response => response.text())
              .then(html => document.getElementById('table-container').innerHTML = html);
            }

            // Toggle sidebar visibility
            function toggleSidebar() {
              const sidebar = document.querySelector('aside');
                sidebar.classList.toggle('translate-x-[100%]');
            }
          </script>
        </section>
      </main>
    </body>
  </html>
