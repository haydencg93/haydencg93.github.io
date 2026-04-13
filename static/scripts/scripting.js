document.getElementById('unlock-btn').addEventListener('click', function() {
    // 1. Prompt the user for the password
    const password = prompt("Please enter the password to view protected content:");
    
    if (password) {
        /* 2. Attempt to navigate to a folder named exactly after the password.
           Requirement: "Do NOT list the plain-text password anywhere in your HTML/JS"
           By using the variable 'password' in the fetch/redirect, we avoid hardcoding it.
        */
        const protectedPath = `protected/${password}/index.html`;

        // Check if the page exists before redirecting (optional but better UX)
        fetch(protectedPath)
            .then(response => {
                if (response.ok) {
                    // 3. Redirect to the protected area
                    window.location.href = protectedPath;
                } else {
                    alert("Incorrect password. Access Denied.");
                }
            })
            .catch(err => {
                console.error("Error checking path:", err);
                alert("An error occurred. Please try again.");
            });
    }
});