/**
 * Hayden's Portfolio Scripting
 * Enhanced with Scroll Animations & Better Form UX
 */

let _supabase;

/**
 * Initialize Supabase and UI Features
 */
async function init() {
    try {
        const response = await fetch('../static/scripts/CONFIG.json');
        if (!response.ok) throw new Error("Could not load configuration.");
        
        const config = await response.json();
        _supabase = supabase.createClient(config.SUPABASE_URL, config.SUPABASE_ANON_KEY);
        
        console.log("Supabase linked successfully.");
        setupForms();
        initAnimations();
    } catch (err) {
        console.error("Initialization error:", err);
        // Fallback for animations even if DB fails
        initAnimations();
    }
}

/**
 * Scroll Reveal Animations
 */
function initAnimations() {
    const observerOptions = {
        threshold: 0.1
    };

    const observer = new IntersectionObserver((entries) => {
        entries.forEach(entry => {
            if (entry.isIntersecting) {
                entry.target.classList.add('visible');
            }
        });
    }, observerOptions);

    document.querySelectorAll('.fade-in').forEach(el => {
        observer.observe(el);
    });
}

document.addEventListener('DOMContentLoaded', init);